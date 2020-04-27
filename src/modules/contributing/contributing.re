
open Contributing_styles;
open Utils;

[@react.component]
let make = () => {
    <div className="contributing-guide">
        <Container>
            <article className={Styles.article ++ " markdown-body"} dangerouslySetInnerHTML={ 
                "__html": marked(import("../../../guide/index.md")) 
            } />
        </Container>
    </div>    
}