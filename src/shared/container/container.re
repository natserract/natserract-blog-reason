open Container_styles;

[@react.component]
let make = (~children) => 
    <div className=Styles.container>
        children
    </div>
