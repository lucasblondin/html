
var buttonReponse = document.getElementById("boutonVoir");
var divReponse = document.getElementById("hide");
var list = document.getElementsByClassName('rep');
var tableau = document.getElementsByClassName("tab");
var cellules = document.getElementsByClassName("cellule");
var tableauInitial = document.getElementsByClassName("init");
var reponsesTrouvees = "";

var general = 0;

// depart
function sleep(milliseconds) {
    const date = Date.now();
    let currentDate = null;
    do {
      currentDate = Date.now();
    } while (currentDate - date < milliseconds);
  }

//console.log( "taille : " +  list.length-1);
deplacementDepart(list.length-1,list.length-1);





$('#listes label').on('click',function() {
    var requete = new XMLHttpRequest();
    
    $(this).css('color','blue');
    var test = $(this).text();
    var enigme = test.split(' ');

    console.log(enigme[0]);
    
    var selection = enigme[0];
    requete.open("GET","show?" + selection,false);
    requete.send(null);

    //document.getElementById("centre").innerHTML = requete.responseText;
    console.log(requete.responseText);

    var requeteReponse = new XMLHttpRequest();
    requeteReponse.open("GET","reponse?" + selection,false);
    requeteReponse.send(null);


    //document.getElementById("hide").innerHTML = requeteReponse.responseText;
    document.getElementById("hide").innerHTML = requete.responseText;
    var listReponse = document.getElementById("hide");
    console.log(listReponse.innerText);
    

    var words = requeteReponse.responseText.split(' ');
    for(i = 0 ; i < listReponse.length;i++){
        //console.log(words[listReponse.length  - i]);
        listReponse[i].innerText =  words[listReponse.length - i];
        //console.log(document.getElementById("hide")[i].innerHTML);
    }
    var nouveau = document.getElementsByClassName('rep').length;
    //console.log("taille :" + nouveau);
    deplacement(nouveau-1,nouveau-1);
});


buttonReponse.onclick = function(){
    if(divReponse.className == "hidden"){
        divReponse.className = "show";
        buttonReponse.innerText = "cacher";
    }else{
        divReponse.className = "hidden";
        buttonReponse.innerText = "Voir le resultat";

        /*
        for(i = 0 ; i < cellules.length;i++){
            document.getElementsByClassName("cellule")[i].innerText = tableauInitial[i].innerText; 
            document.getElementsByClassName("cellule")[i].setAttribute('style','');
        }*/
    }    
}

function paint(count){
    for(i = 0 ; i < cellules.length;i++){
        document.getElementsByClassName("cellule")[i].innerText = tableauInitial[i].innerText; 
        document.getElementsByClassName("cellule")[i].setAttribute('style','');
    }

    $('textarea').empty();

    console.log("taille : " + (list.length-1) - count + " " + (list[count].innerText));
    deptest((list.length-1) - count, (list.length-1) - count);
}

$('#avance').on('click',function() {
    general++;
    var count = general;
    paint(count);
});

$('#retour').on('click',function() {
    general--;
    var count = general;
    paint(count);
});


$('#hide label').on('click',function() {
    $(this).css('color','blue');
    
    var count = 0; 
    while(list[count].innerText != this.innerText){
        count++;
    }
    console.log(count);
    paint(count);
});

var counting = 0;
var premier ;
var deuxieme;


$('td').on('click',function() {
    if(counting == 0){
        $(this).css('outline','2px solid green');
        premier = $(this);
        counting++;
    }else {
        $(this).css('outline','2px solid red');
        deuxieme = $(this);
        counting = 0;

        premier.css('outline','none');
        deuxieme.css('outline','none');
        
        //console.log("Premier : " + premier.attr('id') + " Deuxieme = " + deuxieme.attr('id'));
        var res = codeUnCoup(premier.attr('id'),deuxieme.attr('id'),"deplacement");

        if(res == "correcte"){
            //console.log(res);
            $('h4').empty();
            $('h4').append("Notez vos coups ! " + res);
        }else {
            //console.log(res);
            $('h4').empty();
            $('h4').append("Notez vos coups ! " + res);
        }
    }
});

function color(code){

    var positionInitX = code.innerText[2].charCodeAt(0) - 97;
    var positionInitY = parseInt(code.innerText[3]);

    var positionFinalX = code.innerText[4].charCodeAt(0) - 97;
    var positionFinalY = parseInt(code.innerText[5]);

    cellules[(positionFinalX) + (8 *(8 - positionFinalY))].setAttribute('style','background-color:red;');
    cellules[(positionInitX) + ( 8 * (8 - positionInitY))].setAttribute('style','background-color:green;');
}


function deplacement(tour,max){
    
    if(tour == -1){
        return;
    }
    //console.log("tour : " + tour + " Max : " + max);
    deplacement(tour-1);
    decodeCoup(list[tour],tour);
}

function deptest(tour){
    //console.log(" tour = " + tour );
    var fin = list.length;
    while(fin > ((list.length-1) - tour)){
        fin--;
        console.log("position = " + fin + "  " + list[fin].innerText );
        decodeCoup(list[fin],fin);
    }
}

function deplacementDepart(tour,max){
    
    if(tour == -1){
        return;
    }

    if(tour < 0){
        tour = 0;
    }
    //console.log(list[max - tour].innerText + " tour =" + tour);
    deplacementDepart(tour-1,max);
    decodeCoup(list[max - tour],tour);
}

function decodeCoup(code,index){
    

    if(index%2==0){
        var couleur = "w";
    }else {
        var couleur = "b";
    }
    if(code.innerText[0].charCodeAt(0) < 'a'.charCodeAt(0) ){
    var piece = code.innerText[0];

    var positionInitX = code.innerText[1].charCodeAt(0) - 97;
    var positionInitY = parseInt(code.innerText[2]);

    var positionFinalX = code.innerText[4].charCodeAt(0) - 97;
    var positionFinalY = parseInt(code.innerText[5]);
    }else {      
    var piece = "P";
    
    var positionInitX = code.innerText[0].charCodeAt(0) - 97;
    var positionInitY = parseInt(code.innerText[1]);
    
    var positionFinalX = code.innerText[3].charCodeAt(0) - 97;
    var positionFinalY = parseInt(code.innerText[4]);
    
    }
    //console.log("piece = " + piece + " couleur = " + couleur + " pIx = " + positionInitX + " pIy = " + positionInitY + " pFx = " + positionFinalX + " pFy = " + positionFinalY);


   //console.log((positionInitX) + ( 8 * (8 - positionInitY)));
    //console.log((positionFinalX) + (8 *(8 - positionFinalY)));

    if(index >= 0){
        var P ;
        
        if (couleur == 'w'){
            if(piece == 'K'){
                P = '♔';
            }else if(piece == 'Q'){
                P = '♕';
            }else if(piece == 'B'){
                P = '♗';
            }else if(piece == 'N'){
                P = '♘';
            }else if(piece == 'R'){
                P = '♖';
            }else if(piece == 'P'){
                P = '♙';
            }
        }else if (couleur == 'b'){
            if(piece == 'K'){
                P = '♚';
            }else if(piece == 'Q'){
                P = '♛';
            }else if(piece == 'B'){
                P = '♝';
            }else if(piece == 'N'){
                P = '♞';
            }else if(piece == 'P'){
                P = '♟';
            }
        }
        
        //console.log(P);

        $('textarea').append( P + code.innerText[2] + positionInitY + "x" + code.innerText[4] + positionFinalY + ", ");
    }
    
    cellules[(positionFinalX) + (8 *(8 - positionFinalY))].innerText = cellules[(positionInitX) + ( 8 * (8 - positionInitY))].innerText;
    cellules[(positionInitX) + (8 * (8 - positionInitY))].innerText = " ";
}


function codeUnCoup(coup1,coup2,dep){
    //console.log("coup1 = " + coup1 + "/ coup2 = " + coup2);
    
    var c1Chiffre = 8 - (Math.trunc(coup1/8)) ;

    //console.log("après division " + c1Chiffre);
    var c1Lettre = String.fromCharCode(97 + coup1%8);
    var piece1 = document.getElementById(coup1).innerText;

    var c2Chiffre = 8 - (Math.trunc(coup2/8));
	//console.log("après division " + c2Chiffre);
    var c2Lettre = String.fromCharCode(97 + coup2%8);
    var piece2 = document.getElementById(coup2).innerText;

    var text = document.getElementById("story").value;
    var words = text.split(',');

    var positionActu = (list.length) - (words.length - 1);

    reponsesTrouvees += piece1 + c1Lettre + c1Chiffre  + "x" + piece2 + c2Lettre +  c2Chiffre  + ", ";
    //$('textarea').append( piece1 + c1Lettre + c1Chiffre  + "x" + piece2 + c2Lettre +  c2Chiffre  + ", ");
    //console.log(list[words.length-1].innerText);

    //console.log(words);
    //console.log("position actuelle " + positionActu);

    if(list[positionActu].innerText[0].charCodeAt(0) < 'a'.charCodeAt(0) ){
	var r = list[positionActu].innerText[0] + c2Lettre + c2Chiffre + list[positionActu].innerText[3] + c1Lettre +  c1Chiffre;
    }else {
	var r = c2Lettre + c2Chiffre + list[positionActu].innerText[2] + c1Lettre +  c1Chiffre;
    }

    var comp = list[positionActu].innerText.substring(0, 6);
    
    //console.log("r    = " + r);
    //console.log("comp = " + comp);

    if(r == comp){
        
        //console.log(list[words.length-1].innerText + " " +  words.length );

        list[positionActu].style.color = "green";

        if(dep == "deplacement"){
        
        var count = 0; 
        while(list[count].innerText != list[positionActu+1].innerText){
                count++;
        }


        for(i = 0 ; i < cellules.length;i++){
            document.getElementsByClassName("cellule")[i].innerText = tableauInitial[i].innerText; 
            document.getElementsByClassName("cellule")[i].setAttribute('style','');
        }

        $('textarea').empty();
        console.log( "position" + (list.length-1) - count);
        deptest((list.length-1) - count, count-1);
        }

        //$('textarea').append( piece1 + c1Lettre + c1Chiffre  + "x" + piece2 + c2Lettre +  c2Chiffre  + ", ");
        return "correcte";
    }
        return "incorrecte";
}

  var oldVal = "";

  $("#story").on("change keyup paste", function() {
      var currentVal = $(this).val();
      if(currentVal == oldVal) {
          return; //check to prevent multiple simultaneous triggers
      }
  
      oldVal = currentVal;
      //action to be performed on textarea changed
      var text = document.getElementById("story").value;
      //console.log(text);
      var words = text.split(',');
      //deplacement(words.length-1);
  });

