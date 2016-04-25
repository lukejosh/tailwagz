function templatemo_map() {
                $('.google-map').gmap3({
                    marker:{
                        address: '16.8496189,96.1288854' 
                    },
                        map:{
                        options:{
                        zoom: 15,
                        scrollwheel: false,
                        streetViewControl : true
                        }
                    }
                });
            }

function validate_password() {
    var password = document.getElementById("password")
    var confPass = document.getElementById("confpassword")
    console.log("hello")
    if (password.value != confPass.value) {
        confPass.setCustomValidity("Passwords Do Not Match");
    }
    else {
        confPass.setCustomValidity('')
    }
}