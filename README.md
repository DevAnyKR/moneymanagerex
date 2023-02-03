[<img src="https://raw.githubusercontent.com/moneymanagerex/moneymanagerex/master/resources/mmexlogo.png" height="32"/>][website]
MoneyManager Ex (MMEX)
================

[![stable]][GitHubLatest] [![unstable]][GitHubDL] [![a]][AppVeyor]
[![ci]][CircleCI] [![s]][SourceForgeDL] [![gha]][GitHubDL] [![ghl]][GitHubLatest]
[![p]][packagecloud] [![w]][website] [![i]][GitHubIssues] [![cd]][CodeDocs]
[![c]][contributors] [![l]](LICENSE) [![o]][OpenHub]

[MoneyManager Ex (MMEX)](https://moneymanagerex.org/) is a free/libre, open-source, cross-platform, easy-to-use personal
finance software. It helps organize finances and track cash flow.

MMEX includes all the basic features that 90% of users would want to see in a
personal finance application. The design goals are to concentrate on
simplicity and user-friendliness – an application that can be used everyday.

<table border="0">
    <tr>
        <td>
            <img src="https://raw.githubusercontent.com/moneymanagerex/Art/master/PC/mmex1.png" 
                 alt="Dashboard" 
                 title="Dashboard">
        </td>
        <td>
            <img src="https://raw.githubusercontent.com/moneymanagerex/Art/master/PC/mmex2.png" 
                 alt="Payee Report" 
                 title="Payee Report">
        </td>
    </tr>
    <tr>
        <td>
            <img src="https://raw.githubusercontent.com/moneymanagerex/Art/master/PC/mmex3.png" 
                 alt="Transaction Filter and Organize Categories" 
                 title="Transaction Filter and Organize Categories">
        </td>
        <td>
            <img src="https://raw.githubusercontent.com/moneymanagerex/Art/master/PC/mmex4a.png" 
                 alt="Budget Setup" 
                 title="Budget Setup">
        </td>
    </tr>
</table>

Main features
================

- Fast, intuitive and functional
- Checking, credit card, savings, stock investment and asset accounts
- Reminders for recurring bills and deposits
- Budgeting and cash flow forecasting
- Simple one-click reporting with graphs and charts
- Import data from [Comma-Separated Values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values) and [Quicken Interchange Format (QIF)](https://en.wikipedia.org/wiki/Quicken_Interchange_Format) files
- [Custom Reports](https://github.com/moneymanagerex/general-reports#general-reports)
- Installation not required: portable versions run from a USB or a flash drive
- Nonproprietary [SQLite](https://www.sqlite.org/) database with [Advanced Encryption Standard (AES)](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard)
- Cross-platform, available for desktop and mobile operating systems
- [International language support](https://crowdin.com/project/moneymanagerex) 


Download
================

[Download](https://github.com/moneymanagerex/moneymanagerex/releases/) the latest version of MMEX for GNU/Linux, macOS and Windows.

[![Github All Releases](https://img.shields.io/github/downloads/moneymanagerex/moneymanagerex/total.svg)](https://tooomm.github.io/github-release-stats/?username=moneymanagerex&repository=moneymanagerex)



Credits
================

MMEX is mainly written in C++11.  
This software uses the following open-source packages:

[wxWidgets] 3.0+ 

[wxSqlite3] 

[SQLite3] 

[RapidJSON]

[ChartNew.JS] (outdated)

[ApexCharts.js]

[html-template] 

[libcurl]

Supported platforms
================

- Most [Unix variants](https://en.wikipedia.org/wiki/Category:Unix_variants) using the [GTK+ toolkit](https://www.gtk.org/) (version 2.6 or newer or 3.x)
- OS X (10.9 or newer) and macOS using Cocoa
- Windows XP, 2003, Vista, 7, 8, 10 and 11

External public resources
================

[Slack] | [Forum] | [Wiki] | [Facebook] | [YouTube] | [Crowdin] | [SourceForge] | [GitHub]
| [Docker images] | [Twitter] [![tw]][Twitter]

Tips
================

* Database file (both regular and encrypted) can be opened directly
  with [wxsqliteplus]
* Download dozens of useful reports from the [general reports] repository
* Star this repository if you feel it is helpful [![st]][stargazers]

[website]: https://moneymanagerex.org "MMEX website"
[AppVeyor]: https://ci.appveyor.com/project/whalley/moneymanagerex "AppVeyor CI"
[CircleCI]: https://app.circleci.com/pipelines/github/moneymanagerex/moneymanagerex?branch=master "Circle CI"
[OpenHub]: https://www.openhub.net/p/moneymanagerex "Open Hub report"
[GitHubIssues]: https://github.com/moneymanagerex/moneymanagerex/issues "open issues on GitHub"
[SourceForgeDL]: https://sourceforge.net/projects/moneymanagerex/files/latest "SourceForge downloads"
[GitHubDL]: https://ci.appveyor.com/project/moneymanagerex/moneymanagerex/history "appveyor"
[contributors]: https://github.com/moneymanagerex/moneymanagerex/graphs/contributors "contributors to Git repo"
[GitHubLatest]: https://github.com/moneymanagerex/moneymanagerex/releases/latest "GitHub latest stable downloads"
[packagecloud]: https://packagecloud.io/moneymanagerex/ "packagecloud DEB & RPM repository"
[CodeDocs]: https://codedocs.xyz/moneymanagerex/moneymanagerex/ "doxygen generated source code documentation"
[Slack]: http://slack.moneymanagerex.org/
[Forum]: https://forum.moneymanagerex.org
[Wiki]: https://sourceforge.net/p/moneymanagerex/wiki/mmex
[Facebook]: https://www.facebook.com/MoneyManagerEx
[YouTube]: https://www.youtube.com/channel/UCAqVC0fOt6C5OnGv_DzE0wg
[SourceForge]: https://sourceforge.net/p/moneymanagerex
[GitHub]: https://github.com/moneymanagerex
[Docker images]: https://hub.docker.com/r/moneymanagerex/
[Twitter]: https://twitter.com/MoneyManagerEx
[wxWidgets]: http://wxwidgets.org/
[wxSqlite3]: https://github.com/utelle/wxsqlite3
[SQLite3]: http://sqlite.org/
[Mongoose]: https://github.com/cesanta/mongoose
[RapidJSON]: http://rapidjson.org/
[ChartNew.JS]: https://github.com/FVANCOP/ChartNew.js
[ApexCharts.js]: https://apexcharts.com/
[html-template]: https://github.com/moneymanagerex/html-template
[libcurl]: https://curl.haxx.se/libcurl/
[wxsqliteplus]: https://github.com/guanlisheng/wxsqliteplus
[general reports]: https://github.com/moneymanagerex/general-reports
[stargazers]: https://github.com/moneymanagerex/moneymanagerex/stargazers
[a]: https://img.shields.io/appveyor/ci/moneymanagerex/moneymanagerex/master.svg?label=windows&logoWidth=0.01
[ci]: https://img.shields.io/circleci/build/github/moneymanagerex/moneymanagerex/master?label=linux/mac
[o]: http://www.openhub.net/p/moneymanagerex/widgets/project_thin_badge.gif
[i]: https://img.shields.io/github/issues-raw/moneymanagerex/moneymanagerex.svg?label=gh%20issues
[c]: https://img.shields.io/github/contributors/moneymanagerex/moneymanagerex.svg
[cd]: https://codedocs.xyz/moneymanagerex/moneymanagerex.svg
[l]: https://img.shields.io/badge/license-GPL2-blue.svg
[s]: https://img.shields.io/sourceforge/dt/moneymanagerex.svg?label=%20sf&logoWidth=8&logo=data%3Aimage%2Fpng%3Bbase64%2CiVBORw0KGgoAAAANSUhEUgAAAC0AAAA4CAMAAABe34GAAAAACVBMVEUAAAAAAAD%2F%2F%2F%2BD3c%2FSAAAAAnRSTlMATX7%2B8BUAAABeSURBVHgB7coxCoBAAAOw0%2F8%2FWtA1tLs0c85Et21vb%2F9pe1jsyP7OrSOzI5eOfL1K%2FlLuyO7O7s7oLbs7uzu7O7s7uzv37uzu7O7sjly6szty6s7uzoZcurMhJ87nAdpRCKWC0tGVAAAAAElFTkSuQmCC
[gha]: https://img.shields.io/github/downloads/moneymanagerex/moneymanagerex/total.svg?label=%20gh&logoWidth=8&logo=data%3Aimage%2Fpng%3Bbase64%2CiVBORw0KGgoAAAANSUhEUgAAAC0AAAA4CAMAAABe34GAAAAACVBMVEUAAAAAAAD%2F%2F%2F%2BD3c%2FSAAAAAnRSTlMATX7%2B8BUAAABeSURBVHgB7coxCoBAAAOw0%2F8%2FWtA1tLs0c85Et21vb%2F9pe1jsyP7OrSOzI5eOfL1K%2FlLuyO7O7s7oLbs7uzu7O7s7uzv37uzu7O7sjly6szty6s7uzoZcurMhJ87nAdpRCKWC0tGVAAAAAElFTkSuQmCC
[ghl]: https://img.shields.io/github/downloads/moneymanagerex/moneymanagerex/latest/total.svg?label=%20gh%20latest&logoWidth=8&logo=data%3Aimage%2Fpng%3Bbase64%2CiVBORw0KGgoAAAANSUhEUgAAAC0AAAA4CAMAAABe34GAAAAACVBMVEUAAAAAAAD%2F%2F%2F%2BD3c%2FSAAAAAnRSTlMATX7%2B8BUAAABeSURBVHgB7coxCoBAAAOw0%2F8%2FWtA1tLs0c85Et21vb%2F9pe1jsyP7OrSOzI5eOfL1K%2FlLuyO7O7s7oLbs7uzu7O7s7uzv37uzu7O7sjly6szty6s7uzoZcurMhJ87nAdpRCKWC0tGVAAAAAElFTkSuQmCC
[w]: https://img.shields.io/website-up-down-brightgreen-red/https/moneymanagerex.org/.svg
[p]: https://img.shields.io/website-up-down-brightgreen-red/https/packagecloud.io/moneymanagerex/.svg?label=deb%20rpm%20repo
[stable]: https://img.shields.io/github/release/moneymanagerex/moneymanagerex.svg?label=stable

[unstable]: https://img.shields.io/badge/unstable-beta-yellow
[st]: https://img.shields.io/github/stars/moneymanagerex/moneymanagerex.svg?&label=GitHub&style=social&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA4AAAAOCAYAAAAfSC3RAAAA50lEQVQoz5XSr0oFQRzF8c%2FuBd0iiCYviHi1GXwABYMugiaLmKw3iF18AetF8B1MNouDb6AICgbfwCqGKf4JrjIse132lGHOnC%2FMnN%2FQoBjMxyDEYN8Y5WP8IbYwisFMF%2FCkWuew2QrGYCIGI%2FQS%2BzQGs3Uwi8EOjrFReZMNN4nIcI9bnGUxeMOUblrJsYevDtAlXrLqbUc4%2F6esX90Upe2%2FcorSBQ5boGvsNrX63AK%2B4rMJXG8Bl9IxpeBaLfhY2y%2Bm%2Bbx2AA84KEqrWMYVPtBP81nya%2FpYwFNRek%2F8HgaYxl1R%2FozuGyXRMhoIJiaoAAAAAElFTkSuQmCC
[tw]: https://img.shields.io/twitter/follow/MoneyManagerEx.svg?style=social&label=follow
[Buy us a Cofee]: https://cash.me/$guanlisheng/1
[Donate via PayPal]: https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=moneymanagerex%40gmail%2ecom&lc=US&item_name=MoneyManagerEx&no_note=0&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest
[Crowdin]: https://crowdin.com/project/moneymanagerex

Support
================

[![Donate via PayPal](https://www.paypalobjects.com/webstatic/mktg/Logo/pp-logo-100px.png)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=moneymanagerex%40gmail%2ecom&lc=US&item_name=MoneyManagerEx&no_note=0&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest";)

or

[![Buy us a Cofee](https://www.buymeacoffee.com/assets/img/custom_images/purple_img.png)](https://cash.me/$guanlisheng/1)

You may also like…
================

- [MMEX for Android](https://github.com/moneymanagerex/android-money-manager-ex)


License
================

[GPL](LICENSE)

### Stargazers over time

[![Stargazers over time](https://starchart.cc/moneymanagerex/moneymanagerex.svg)](https://starchart.cc/moneymanagerex/moneymanagerex)
