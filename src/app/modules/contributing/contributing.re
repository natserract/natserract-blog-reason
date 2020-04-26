
open Post_styles;
open Utils;

[@react.component]
let make = () => {
    <div className="contributing-guide">
        <Container>
            <article dangerouslySetInnerHTML={ 
                "__html": marked(import("../../../../contributing/index.md")) 
            } />
        </Container>
    </div>    
}