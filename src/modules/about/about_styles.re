
module Styles = {
    open Css;

    let title = style([
        marginTop(`px(0)),
        marginBottom(`px(15)),
        float(`left)
    ]);

    let img_author = style([
        float(`right),
        width(`px(120)),
        height(`px(145)),
        marginLeft(`px(15))
    ]);

    let content = style([
        clear(`left),
        overflow(`auto),
    ]);

    let work_experience = style([
        selector(
            ".work-experience__item", [
                marginBottom(`px(30)),

                selector(
                    ".work-experience-header", [
                        marginBottom(`px(20)),

                        selector(
                            "span", [
                                display(`block)
                            ]
                        ),

                        selector(
                            ".province", [
                                opacity(0.5)
                            ]
                        )
                    ]
                )
            ]
        )
    ]);

    let contributions = style([
        selector(
            ".contributions-item", [
                marginBottom(`px(30)),
                
                selector(
                    "h4", [
                        fontSize(`px(18)),
                        fontStyle(`italic),
                        display(`block),
                        marginBottom(`px(5)),
                    ]
                ),
                selector(
                    "span", [
                        display(`block)
                    ]
                ),
                selector(
                    ".event-name", [
                        lineHeight(`em(1.5)),
                    ]
                )       
            ]
        )
    ]);
}