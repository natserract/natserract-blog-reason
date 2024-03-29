// Your provider here

open Utils;
open App_routes;
    
let applyToHeadEl = document##createElement("style");
document##head##appendChild(applyToHeadEl);
applyToHeadEl##innerHTML #= App_styles.globalStyles;


[@react.component]
let make = () => {
    let route = appRoutesConfig();
    
    <Store>
        <main className="wrapper" style=(
            ReactDOMRe.Style.make(
                ~minHeight="100%", 
                ~display="grid", 
                ~gridTemplateRows="auto 1fr auto", 
                ~background="#fff",
                ~zIndex="10",
                ~position="relative",
                ~maxWidth="50%",
                ~margin="0 auto",

            ())
        )>
            <Header/>
            ( switch (route) {
                | Post(slug) => <Post slug/>
                | Contributing => <Contributing/>
                | About => <About/>
                | Home => <Home/>
                | _ => "Not found" -> textEl
            })
            <Footer/>
        </main>
    </Store>
};