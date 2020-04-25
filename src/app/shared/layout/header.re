open Core.Models.Posts;


[@react.component]
let make = () => {
    <ul>
        <li><Link href="/">(Utils.textEl("Home"))</Link></li>
        <li><Link href="/#/about">(Utils.textEl("About"))</Link></li>
    </ul>
}