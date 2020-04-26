
module Styles = {
    open Css;

    let heading = style([
        fontSize(`px(30))
    ]);

    let list = style([
        margin(`px(0)),
        padding(`px(0)),
        
        selector(
            "li", [
                display(`block),
                listStyleType(`none),
                marginBottom(`px(5)),

                selector(
                    "a", [
                        display(`block),
                        color(`hex("006600"))
                    ]
                ), 

                selector(
                    "span", [
                        paddingLeft(`px(15))
                    ]
                )
            ]
        )
    ]);
}