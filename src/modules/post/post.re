
open Post_styles;
open Utils;

[@react.component]
let make = (~slug: string) => {
    <div className="article-detail">
        <Container>
            <article className={Styles.article ++ " markdown-body"} dangerouslySetInnerHTML={ 
                "__html": marked(import("../../../posts/"++slug++"/index.md")) 
            } />
        </Container>
    </div>    
}