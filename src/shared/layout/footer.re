open Footer_styles;

[@react.component]
let make = () => {
    <footer className=Styles.footer>
        <Container>
            <span className=Styles.footer_copyright>
                "2019  Alfin Surya. Unless otherwise noted, these posts are made available under a Creative Commons Attribution License." -> Utils.textEl
            </span>
        </Container>
    </footer>
}