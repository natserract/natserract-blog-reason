
module Styles = {
    open Css;

    let footer = style([
        paddingBottom(`px(20))
    ]);

    let footer_copyright = style([
        fontSize(`px(13)),
        lineHeight(`em(1.2)),
        display(`block)
    ]);
}