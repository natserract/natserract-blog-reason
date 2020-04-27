
module Styles = {
    open Css;
    
    let article = style([
        background(`hex("fff")),

        selector(
            "h1:first-child", [
                marginTop(`px(0)),
                borderBottom(`px(0), `solid, `transparent),
                paddingBottom(`px(0)),
            ]
        ),


        selector(
            "img", [
                width(`percent(100.0))
            ]
        )
    ]);
}