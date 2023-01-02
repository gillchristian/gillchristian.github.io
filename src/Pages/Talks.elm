module Pages.Talks exposing (page)

import Components.Sidebar
import Components.Header exposing (Page(..))
import Html exposing (Html)
import View exposing (View)


page : View msg
page =
  Components.Sidebar.view
    Talks
    { page =
        { title = "Pages.Talks"
        , body = [ Html.text "/talks" ]
        }
    }
