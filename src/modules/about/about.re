
open Utils;
open About_styles;

[@react.component]
let make = () => {
    <div className="about">
        <Container>
            <div className="about-header">
                <h1 className=Styles.title>"Alfin Surya" -> textEl</h1>
            </div>
            
            <div className=Styles.img_author>
                <img src="../../../assets/img/author.jpg"/>
            </div>

            <div className=Styles.content>
                <em>"Front-End Engineer" -> textEl</em>
                <p>"I'm Alfin Surya, an designer, frontend/web developer currently residing in Bali. Specializing in developing websites and web applications." -> textEl</p>

                <p>
                    "Being a Polyglot engineer comfortable working across the stack, but with a front-end focus. Interest in types, functional programming and low-level language as a backend service like Rust and Golang.
                    Always open to learning new technologies as long as there interesting projects to be involved in. "
                        -> textEl
                </p>

                <h2> "Skills" -> textEl</h2>
                <p>"Quick to internalize new concepts. Highly motivated and resourceful self-learner. Thrives in fast-paced, high-intensity environments without sacrificing attention to detail. Effective, diplomatic communicator in difficult or delicate situations." -> textEl</p>

                <h2> "Techs" -> textEl</h2>
                <p>"Productive when working with a range of languages including Javascript, TypeScript, ReasonML, React, Angular and Rust, as well as modern ecosystem tools such as Git/Github, Linux(Basic), RESTFUL API design, and many more." -> textEl</p>


                <div className=Styles.work_experience>
                    <h2> "Work Experience" -> textEl</h2>
                    <div className="work-experience__item">
                        <div className="work-experience-header">
                            <span><b>"Salt" -> textEl</b></span>
                            <span>"Frontend Developer" -> textEl</span>
                            <span>"April 2020 - Present" -> textEl </span>
                            <span className="province">"Jakarta, Indonesia" -> textEl</span>
                        </div>
                        <div className="work-experience-content">
                            <p>"As a frontend developer, primary role is in building user-facing web products, collaborate with UI/UX designer and backend developer to deliver the best product and user experience." -> textEl</p>

                            <p>
                                "Develop using modern JavaScript: Angular, React, CSS Preprocessors, webpack and many more." -> textEl
                            </p>
                        </div>
                    </div>
                    
                    <div className="work-experience__item">
                        <div className="work-experience-header">
                            <span><b>"Fantasktic, Inc" -> textEl</b></span>
                            <span>"Frontend Developer" -> textEl</span>
                            <span>"Jan - Apr 2020 (Full-time)" -> textEl </span>
                            <span className="province">"Bali Province, Indonesia" -> textEl</span>
                        </div>
                        <div className="work-experience-content">
                            "In this company, my responsibility is migration non WordPress site or existing site to a new host to the WordPress platform." -> textEl
                        </div>
                    </div>

                    <div className="work-experience__item">
                        <div className="work-experience-header">
                            <span><b>"Jeg Studio" -> textEl</b></span>
                            <span>"Web Designer" -> textEl</span>
                            <span>"June - August 2018 (Internship)" -> textEl </span>
                            <span className="province">"Bali Province, Indonesia" -> textEl</span>
                        </div>
                        <div className="work-experience-content">
                            "At Jeg Studio our goal is to built unique news and magazine WordPress themes and make it amazing-looking that are naturally easy to use and customize, without any compromise on performance." -> textEl
                        </div>
                    </div>
                </div>



                <h2> "Contributions" -> textEl</h2>
                <div className=Styles.contributions>
                    <div className="contributions-item">
                        <h4>"Speaker" -> textEl</h4>
                        <span className="event-name">"ReactJS Indonesia" -> textEl</span>
                        <span className="event-data">"Nov 2019" -> textEl</span>

                        <p>"An online meetup held by ReactJS ID Community, where I filled in the topic of 'How to build your own Jest - Pure JavaScript'"-> textEl</p>
                    </div>
                </div>
            </div>
        </Container>
    </div>
}