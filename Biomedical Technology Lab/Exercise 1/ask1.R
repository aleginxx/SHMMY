library('UsingR')
#ΑΜ = 03120164, άρα x = Energy.consumption

data("wellbeing")
View(wellbeing)

#Ερώτημα 1
#Βρίσκουμε μέσο ό΄ρο
mean(wellbeing$Energy.consumption)

#Ερώτημα 2
#Βρίσκουμε το μέγιστο
wellbeing$Country[wellbeing$Energy.consumption == max(wellbeing$Energy.consumption)]

#Ερώτημα 3
#Αποθηκεύουμε αρχείο με φθίνουσα σειρά για τη στήλη Energy-consumption
wellbeing2 = wellbeing[order(-wellbeing$Energy.consumption),]

#Ερώτημα 4
#Απεικονίζουμε τις 3 πρώτες χώρες του νέου αρχείου
wellbeing2[1:3,1]

#Ερώτημα 5
#Γράφημα Energy.consumption-Well.being
plot(wellbeing$Energy.consumption, wellbeing$Well.being, col = 'green', xlab = "Energy Consumption", ylab = "Well-Being")

#Ερώτημα 6
#Αποθηκεύουμε νέο αρχείο που περιλαμβάνει τις χώρες με Energy.consumption μεγαλύτερο του μέσου όρου
wellbeing3 = wellbeing[wellbeing$Energy.consumption > mean(wellbeing$Energy.consumption)]

#Ερώτημα 7
#Απεικονίζουμε γραφικά τις χώρες του ερωτήματος 6
barplot(wellbeing3$Well.being, col = 'blue', xlab = "Countries whose Energy Consumption levels are above average", ylab = "Well-Being Index")
