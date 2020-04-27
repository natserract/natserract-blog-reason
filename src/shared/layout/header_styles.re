open Css;

module Styles = {

    let nav = style([
        background(`hex("ffffff")),
        zIndex(1000),
        minHeight(`px(70)),
        display(`flex),
        alignItems(`center),
        padding2(`px(10), `px(0)),

        selector(
            "> div", [
                paddingBottom(`px(15)),
                borderBottom(`px(1), `solid, `hex("dcf1d5")),
            ]
        )
    ]);

    let ul = style([
        display(`flex),
        flexDirection(`column),
        alignItems(`center),
        
        selector(
            "ul", [
                width(`percent(100.0)),
                margin(`px(0)),
                padding(`px(0)),
            ]
        ),
        
        selector(
            "ul.menu-list", [
                marginTop(`px(15)),
                display(`flex),
                justifyContent(`spaceBetween),
                
                selector(
                    ".menu-list-right", [
                        selector(
                            "li", [
                                paddingRight(`px(15))
                            ]
                        )
                    ]
                )
            ]
        ),

        selector(
            "li", [
                display(`inlineBlock),
                listStyleType(`none),
                paddingRight(`px(20)),

                selector(
                    "a", [
                        textDecoration(`none),
                        color(`hex("047a04")),
                        fontSize(`px(14)),
                    ]
                )
            ]
        )
    ]);

    let brand = style([

        selector(
            "li", [
                color(`hex("006600")),
                fontWeight(`bold),
                fontStyle(`italic),

                selector(
                    "a", [
                        fontSize(`px(33)),

                        selector(
                            "span", [
                                display(`block),
                                fontSize(`px(12)),
                                fontWeight(`light),
                                opacity(0.7)
                            ]
                        )
                    ]
                )
            ]
        )
    ]);
}