function carregar() {
    var msg = document.getElementById('msg')
    var img = document.getElementById('imagem')
    var data = new Date()
    var horas = data.getHours()

    msg.innerHTML = `Agora são ${horas} horas.` 

    if(horas >= 0 && horas < 12) {
        img.src = 'foto_manha.png'
        document.body.style.background = '#f0c9ba'
    }
    else if (horas <= 18) {
        img.src = 'pexels_tarde.png'
        document.body.style.background = '#bf7d75'
    } else {
        img.src = 'noite.png'
        document.body.style.background = '#191970'
    }
}
