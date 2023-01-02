module Pages.Projects exposing (page)

import Components.Sidebar
import Components.Header exposing (Page(..))
import Html exposing (Html)
import View exposing (View)


page : View msg
page =
  Components.Sidebar.view
    Projects
    { page =
        { title = "Pages.Projects"
        , body = [ Html.text "/projects" ]
        }
    }
