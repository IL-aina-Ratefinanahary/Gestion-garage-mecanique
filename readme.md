# Gestion-garage-mecanique

Cote droit du diagramme des classes UML presque tout code: reste a voir la surcharge du operateur << et en attente de validation ou rectification pour la classe Service(creation d'un nouvel atttribut pour implementer correctement
calculer_prix() et afficher()


Vous pouvez coder la classe Facture en implementant comme voulu dans l'enonce :

//////////// A FAIRE ////////////////////////////
Classe Facture
● ajouter_produit(ProduitFacture) :
○ ajoute un objet ProduitFacture à la liste ;
○ si la facture est finalisée, ça veut dire, le statut est égal à 1, elle lance l'exception
FactureFinaliseeException;
● ajouter_produit(Produit, int) :
○ crée un objet ProduitFacture avec la quantité fournie et l'ajoute ensuite à la liste produits ;
○ si la facture est finalisée, ça veut dire, le statut est égal à 1, elle lance l'exception
FactureFinaliseeException;
● calculer_balance : calcule la somme de tous les produits de la facture ;
● finaliser_facture :
○ si la facture est finalisée, ça veut dire, le statut est égal à 1, elle lance l'exception
FactureFinaliseeException ;
○ sinon:
■ modifie la valeur du statut à 1 ;
■ et pour chaque Pièce de la facture, met à jour la quantité en soustrayant la quantité
qui est vendue.
● enregistrer_facture :
○ si le statut est égal à 0, elle lance l'exception FacturePasFinaliseeException ;
○ sauvegarde un fichier txt avec les données de la Facture telles que présentées dans la
méthode afficher_facture;
○ le nom du fichier doit être facture-n.txt ; où n est l'ID de la facture.
● sortie de la méthode afficher_facture :
