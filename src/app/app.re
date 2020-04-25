// Your provider here

open Utils;
open Shared;
open App_routes;
    
let applyToHeadEl = document##createElement("style");
document##head##appendChild(applyToHeadEl);
applyToHeadEl##innerHTML #= App_styles.globalStyles;


[@react.component]
let make = () => {
    let route = appRoutesConfig();
    
    <Redux>
        <Header/>
        ( switch (route) {
            | Post(slug) => <Post slug/>
            | About => <About/>
            | Home => <Home/>
            | _ => "Not found" -> textEl
        })
        <Footer/>
    </Redux>
};