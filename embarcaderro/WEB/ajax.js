// $ correspond à l'outil Ajax
function refresh() // Permet de démarrer la fonction lors du chargement de la page
{
     
    $.ajax // Envoie une requête HTTP
        ({
            url:"actualise.php", // Ressource ciblée
            type:'POST', // Type de requête HTTP
            datatype:"html", // Type de donnée attendue (ici, HTML)
            success:function(code_HTML,statut) // Contient le HTML à renvoyer
            {
                document.getElementById("actualise").innerHTML = code_HTML; // Renvoie l'élément à l'ID spécifié
            },
             
         
        }); 
     
         
};
setInterval(function(){refresh()
 }, 1000); //delai d'attente du rechargement
