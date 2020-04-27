
module Styles = {
    open Css;

    let footer = style([
        paddingTop(`px(25)),
        paddingBottom(`px(20))
    ]);

    let footer_copyright = style([
        fontSize(`px(13)),
        lineHeight(`em(1.2)),
        display(`block)
    ]);
}