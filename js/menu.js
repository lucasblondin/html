console.log("demarrage");
var demarrage = new XMLHttpRequest();
demarrage.open("GET","cgi-bin/show",false);
demarrage.send(null);
document.getElementById("body").innerHTML = demarrage.responseText;