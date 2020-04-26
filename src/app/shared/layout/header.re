open Core.Models.Posts;
open Header_styles;

[@react.component]
let make = () => {
    <nav className=Styles.nav>
        <Container>
            <div className=Styles.ul>
                <ul className=Styles.brand>
                    <li>
                        <Link href="/">
                            "NATSERRACT" -> Utils.textEl
                            <span>"Thoughts and links about everything" -> Utils.textEl</span>
                        </Link>
                    </li>
                </ul>
                
                <ul className="menu-list">
                    <div className="menu-list-left">
                        <li><Link href="/">(Utils.textEl("Home"))</Link></li>
                        <li><Link href="/#/about">(Utils.textEl("About"))</Link></li>
                        <li><Link href="/#/contributing">(Utils.textEl("Contributing"))</Link></li>
                    </div>
                    <div className="menu-list-right">
                        <li><a href="https://github.com/natserract" target="blank"><i className="icon-github"></i></a></li>
                        <li><a href="https://www.linkedin.com/in/alfinsurya/" target="blank"><i className="icon-linkedin"></i></a></li>
                        <li><a href="mailto:alfins132@gmail.com" target="blank"><i className="icon-envelope"></i></a></li>
                    </div>
                </ul>

            </div>
        </Container>
    </nav>
}