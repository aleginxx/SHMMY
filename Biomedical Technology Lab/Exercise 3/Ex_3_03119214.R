# Part A

#install.packages('RISmed')
library(RISmed)
search_topic<-'e-prescription'
search_query<-EUtilsSummary(search_topic, retmax=50, mindate=2014, maxdate=2014)
summary(search_query)
QueryId(search_query)
records<-EUtilsGet(search_query)

#First 10 titles
pubmed_data_title <-data.frame('Title' = ArticleTitle(records)) 

#Last 2 abstracts
pubmed_data_abstract <-data.frame('Abstract' = AbstractText(records))

head(pubmed_data_title,10)
tail(pubmed_data_abstract,2)

#Part B

#function that returns the number of abstracts
number_of_abstracts <- function (word) {
  
  part_b_search_topic <- word
  query_3 <- EUtilsSummary(part_b_search_topic, mindate = 2018, maxdate = 2022)
  Number <- QueryCount(query_3)
  print(Number)
  
}


#importing comma separated value data
#install.packages("readr")
library(readr)
data<- read.csv(("icd10.csv")#,header = TRUE,sep = ,)


#printing random code
Dis_1<-data[978,2]
print(Dis_1)

#printing random code
Dis_2<-data[111,2]
print(Dis_2)

#printing  random code
Dis_3<-data[603,2]
print(Dis_3)

number_of_abstracts(Dis_1)
number_of_abstracts(Dis_2)
number_of_abstracts(Dis_3)

#plotting Histogram

Data_1 <- EUtilsSummary(Dis_1, mindate = 2020, maxdate = 2022)
get1 <- EUtilsGet(Data_1)
Years1 <- YearPubmed(get1)
hist(Years1, main = 'Diseases', ylab='Articles per year',xlab='Year',border='Black',col=rgb(1,0,0,0.3),xlim = c(2019,2023), breaks = seq(2018.5,2022.5,1))

Data_2 <- EUtilsSummary(Dis_2, mindate = 2020, maxdate = 2022)
get2 <- EUtilsGet(Data_2)
Years2 <- YearPubmed(get2)
hist(Years2, ylab='Articles per year',xlab='Year',border='Black',col=rgb(0,1,0,0.3),xlim = c(2019,2023), breaks = seq(2018.5,2022.5,1),add = TRUE)

Data_3 <- EUtilsSummary(Dis_3, mindate = 2020, maxdate = 2022)
get3 <- EUtilsGet(Data_3)
Years3 <- YearPubmed(get3)
hist(Years3,  ylab='Articles per year',xlab='Year',border='Black',col=rgb(0,0,1,0.3),xlim = c(2019,2023), breaks = seq(2018.5,2022.5,1),add = TRUE)
legend('topright', c(Dis_1,Dis_2,Dis_3), lty = c(1,1,1), col = c('red','darkgray',rgb(1,0,1)),bty = 'n')

#install.packages('treemap')
library(treemap)

group <- c(rep(Dis_1,3),rep(Dis_2,3),rep(Dis_3,3))
subgroup <- c(2020,2021,2022)

#Creating three vectors that have all the appearances of each article per year

Treemap1<-table(Years1)
Treemap_Values_1<-unname(Treemap1)
Treemap2<-table(Years2)
Treemap_Values_2<-unname(Treemap2)
Treemap3<-table(Years3)
Treemap_Values_3<-unname(Treemap3)

#Combining these vectors into one

Treemap_values <- c(Treemap_Values_1,Treemap_Values_2,Treemap_Values_3)

#Plotting the treemap

data_treemap <- data.frame(group,subgroup,Treemap_values)
treemap(data_treemap, index =c('group','subgroup'), vSize = 'Treemap_values',type = 'index')
  



