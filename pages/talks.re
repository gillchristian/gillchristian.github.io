let talks: list(Talk.talk) = [
    {
      title: "Modeling your way to consistency",
      event: "Frontend at Catawiki",
      eventUrl: "https://www.meetup.com/javascript-workshops-amsterdam/events/270592994/",
      description: "How domain modeling can help us to make our apps consistent & safe",
      date: "May 2020",
      links: [
        {
          url: "https://modeling-ts.now.sh",
          label: "Slides"
        },
        {
          url: "https://github.com/gillchristian/modeling-talk",
          label: "Slides (repo)"
        }
      ]
    },
    {
      title: "Modeling your way to consistency",
      event: "dotJS",
      eventUrl: "https://dotjs.io",
      description: "(lightning talk) How domain modeling can help us to make our apps consistent & safe",
      date: "December 2019",
      links: [
        {
          url: "https://www.dotconferences.com/2019/12/christian-gill-modeling-your-way-to-consistency",
          label: "Stream"
        },
        {
          url: "https://bit.ly/dotjs-modeling",
          label: "Slides"
        },
        {
          url: "https://github.com/gillchristian/modeling-lightning",
          label: "Slides (repo)"
        }
      ]
    },
    {
      title: "FP For The People (v2)",
      event: "OdessaJS",
      eventUrl: "http://odessajs.org/",
      description: "Core principles of FP and why to use it on JS",
      date: "July 2019",
      links: [
        {
          url: "https://www.youtube.com/watch?v=0GDkkun8jDQ",
          label: "Stream"
        },
        {
          url: "https://fp-for-the-people-light.gillchristian.now.sh/",
          label: "Slides (updated)"
        },
        {
          url: "https://github.com/gillchristian/fp-for-the-people-v2",
          label: "Slides (repo)"
        }
      ]
    },
    {
      title: "FP for the People",
      event: "Javascript Litoral Meetup",
      eventUrl: "https://www.meetup.com/js-litoral/events/241974602/",
      description: "Core principles of FP and why to use it on JS",
      date: "July 2017",
      links: [
        {
          url: "https://gillchristian.xyz/fp-in-js",
          label: "Slides"
        },
        {
          url: "https://www.youtube.com/watch?v=WIl921KAX0g",
          label: "Stream"
        }
      ]
    },
    {
      title: "React, UI con esteroides",
      event: "Javascript Litoral Meetup",
      eventUrl: "https://www.meetup.com/js-litoral/events/235803581/",
      description: "Introduction to UI development with React",
      date: "Nov 2016",
      links: [
        {
          url: "https://gillchristian.xyz/react-intro",
          label: "Slides"
        },
        {
          url: "https://github.com/javascript-litoral/react-intro",
          label: "Repo"
        },
        {
          url: "https://javascript-litoral.github.io/react-intro",
          label: "Demo app"
        },
        {
          url: "https://youtu.be/REPQDmYnYPk?t=48m2s",
          label: "Stream"
        }
      ]
    },
    {
      title: "Developing with GIT",
      event: "CISL 2016 - UTN - Santa Fe",
      eventUrl: "http://cisl.org.ar/cronograma/10-cisl2016-dia4-santa-fe-utn#.WBHYlMIrLQo",
      description: "Introduction to versioning code with GIT, as part of the \"Introduction to software development\" talk.",
      date: "Oct 2016",
      links: [
        {
          url: "https://gillchristian.xyz/git-workshop",
          label: "Slides"
        },
        {
          url: "https://github.com/gillchristian/git-workshop",
          label: "Repo"
        },
        {
          url: "https://www.facebook.com/psutnfrsf/videos/1158691657585160/",
          label: "Stream"
        }
      ]
    },
    {
      title: "JavaScript ES6",
      event: "Javascript Litoral Meetup",
      eventUrl: "http://www.meetup.com/js-Litoral/events/230947251/",
      description: "EcmaSctip 6 features showcase & usage with Babel.",
      date: "May 2016",
      links: [
        {
          url: "http://slides.com/christiangill/deck",
          label: "Slides"
        },
        {
          url: "https://github.com/JavascriptLitoral/es6-features",
          label: "Repo"
        }
      ]
    },
    {
      title: "Introduction to Angular",
      event: "Javascript Litoral Meetup",
      eventUrl: "http://www.meetup.com/js-Litoral/events/229145986/",
      description: "Introduction to Angular framework, plus some live examples.",
      date: "March 2016",
      links: [
        {
          url: "http://slides.com/christiangill/angular-js-intro",
          label: "Slides"
        },
        {
          url: "https://youtu.be/1qWlIZIar-U?t=5m00s",
          label: "Stream"
        },
        {
          url: "http://gillchristian.xyz/font-awesome-store/",
          label: "Demo"
        },
        {
          url: "https://github.com/gillchristian/font-awesome-store",
          label: "Repo"
        }
      ]
    }
];

let render_talk = (talk: Talk.talk) =>
  <Talk key={talk.title ++ talk.event ++ talk.date} talk />;

[@react.component]
let make = () => {
  <div className="Site">
    <Nav />

    <div className="Site-content">
      <blockquote>
        <p> {ReasonReact.string("I would like to be able to always divide the things up into as many pieces as I can, each of which I understand separately.")} </p>
        <p> {ReasonReact.string("I would like to understand the way of adding things up, independently of what it is I'm adding up.")} </p>
        <p> <i> {ReasonReact.string("Gerald Sussman.")} </i> </p>
      </blockquote>

      <h1> {ReasonReact.string("Talks at meetups & conferences")} </h1>

      <div>
        {talks
          |> List.map(render_talk)
          |> Array.of_list
          |> ReasonReact.array}
      </div>
    </div>

    <Footer />
  </div>;
};

let default = make;

