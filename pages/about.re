[@react.component]
let make = () =>
  <div className="Site">
    <Nav />
    <div className="Site-content">
      <p>
        {ReasonReact.string("From ")}
        <a
          href="https://en.wikipedia.org/wiki/Entre_R%C3%ADos_Province"
          target="_blank"
          rel="noopener noreferrer">
          {ReasonReact.string("Entre Rios, Argentina")}
        </a>
        {ReasonReact.string(" now living in ")}
        <a
          href="https://en.wikipedia.org/wiki/Winschoten"
          target="_blank"
          rel="noopener noreferrer">
          {ReasonReact.string("Winschoten, The Netherlands")}
        </a>
        {ReasonReact.string(".")}
      </p>
      <br />
      <p>
        {ReasonReact.string("I code in Haskell, PureScript, Elm, Reason and Rust ")}
        <Next.Link href="/stream"> {ReasonReact.string("when some are watching")} </Next.Link>
        {
          ReasonReact.string(
            ", looking for ways to bring ideas and patterns from strongly typed functional programming into the mainstream. ",
          )
        }
        {
          ReasonReact.string(
            "If you have something to share about that I'd be happy to hear.",
          )
        }
      </p>
      <br />
      <p>
        {ReasonReact.string("Also, check my ")}
        <a
          href="https://github.com/gillchristian/dotfiles"
          target="_blank"
          rel="noopener noreferrer">
          {ReasonReact.string("dotfiles")}
        </a>
        {
          ReasonReact.string(", every developer should have their dotfiles :)")
        }
      </p>
      <h2> {ReasonReact.string("So far I worked at ...")} </h2>
      /* Scarf */
      <div className="about-job">
        <p>
          <a
            href="https://about.scarf.sh"
            target="_blank"
            rel="noopener noreferrer"
            className="about-job-company">
            <b> {ReasonReact.string("Scarf")} </b>
          </a>
          <small> {ReasonReact.string(" | February 2022 - present")} </small>
        </p>
        <p>
          <b>
            {
              ReasonReact.string(
                "Senior Software Engineer"
              )
            }
          </b>
          {
            ReasonReact.string(
              ", helping open-source maintainers connect with their users and deliver better software.",
            )
          }
        </p>
        <small>
          <Tags
            tags=[
              "TypeScript",
              "Next.js",
              "Node.js",
              "Nix",
              "Haskell",
              "Docker",
              "Kubernetes",
            ]
          />
        </small>
      </div>
      /* Catawiki */
      <div className="about-job">
        <p>
          <a
            href="https://catawiki.com"
            target="_blank"
            rel="noopener noreferrer"
            className="about-job-company">
            <b> {ReasonReact.string("Catawiki")} </b>
          </a>
          <small> {ReasonReact.string(" | October 2019 - January 2022")} </small>
        </p>
        <p>
          <b>
            {
              ReasonReact.string(
                "Senior Software Engineer"
              )
            }
          </b>
          {
            ReasonReact.string(
              ", helped people to buy and sell special objects by improving the payments and shipping experiences.",
            )
          }
        </p>
        <small>
          <Tags
            tags=[
              "TypeScript",
              "fp-ts",
              "React",
              "Node.js",
              "Docker",
              "Kubernetes",
              "CI/CD",
            ]
          />
        </small>
      </div>
      /* HousingAnywhere */
      <div className="about-job">
        <p>
          <a
            href="https://housinganywhere.com"
            target="_blank"
            rel="noopener noreferrer"
            className="about-job-company">
            <b> {ReasonReact.string("HousingAnywhere")} </b>
          </a>
          <small> {ReasonReact.string(" | May 2017 - Sep 2019")} </small>
        </p>
        <p>
          {
            ReasonReact.string(
              "As "
            )
          }
          <b>
            {
              ReasonReact.string(
                "Senior Software Engineer"
              )
            }
          </b>
          {
            ReasonReact.string(
              " and "
            )
          }
          <b>
            {
              ReasonReact.string(
                "Team Lead"
              )
            }
          </b>
          {
            ReasonReact.string(
              " at HousingAnywhere I helped to change the way people, specially students, find accommodation around the world."
            )
          }
        </p>
        <small>
          <Tags
            tags=[
              "TypeScript",
              "React",
              "Node.js",
              "Golang",
              "Docker",
              "Kubernetes",
              "CI/CD",
            ]
          />
        </small>
      </div>
      /* Altoros */
      <div className="about-job">
        <p>
          <a
            href="http://www.altoroslabs.com/"
            target="_blank"
            rel="noopener noreferrer"
            className="about-job-company">
            <b> {ReasonReact.string("Altoros")} </b>
          </a>
          <small> {ReasonReact.string(" | Apr 2016 - May 2017")} </small>
        </p>
        <p>
          {
            ReasonReact.string(
              "Worked with really smart and cool people developing awesomely challenging applications and APIs.",
            )
          }
        </p>
        <small>
          <Tags tags=["JavaScipt", "Node.js", "Angular", "React"] />
        </small>
      </div>
      /* 4r Software */
      <div className="about-job">
        <p>
          <a
            href="http://www.4rsoluciones.com/"
            target="_blank"
            rel="noopener noreferrer"
            className="about-job-company">
            <b> {ReasonReact.string("4r Soluciones")} </b>
          </a>
          <small> {ReasonReact.string(" | Jul 2015 - Mar 2016")} </small>
        </p>
        <p>
          {
            ReasonReact.string(
              "Worked developing visually appealing marketing sites and customized content management systems and applications.",
            )
          }
        </p>
        <small>
          <Tags tags=["PHP", "WordPress", "JavaScript", "Angular", "CSS"] />
        </small>
      </div>
    </div>
    <Footer />
  </div>;

let default = make;
