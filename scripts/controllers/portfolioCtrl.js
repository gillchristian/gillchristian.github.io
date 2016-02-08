angular.module('personalApp.controllers')
  .controller('PortfolioController', ['$scope',
    function($scope) {
      $scope.projects = [
        {
          name: '4r Soluciones',
          description: 'Front-end developer. Custom WordPress themes development, AngularJS webapps.',
          url: 'http://4rsoluciones.com/',
          img: 'assets/img/portfolio/4rsoluciones.jpg',
          tags: ['AngularJS', 'WordPress','php', 'html5', 'ccs3'],
          time: 'Aug 2015 - present'
        },
        {
          name: 'Grandi y Asociados',
          description: 'Front-end developer. WordPress plugins and theme edition, front end development.',
          url: 'http://www.grandiyasociados.net/',
          img: 'assets/img/portfolio/grandi.jpg',
          tags: ['WordPress','php', 'html5', 'ccs3', 'jQuery'],
          time: 'April - August 2015'
        },
        {
          name: 'ADRA Central Asia',
          description: 'WordPress website development and management.',
          url: 'http://adra-central.asia/?lang=en',
          img: 'assets/img/portfolio/ADRAwebsite.jpg',
          tags: ['WordPress','php', 'html5', 'ccs3'],
          time: 'March 2014 - January 2015'
        },
      ];
      
      $scope.personals = [
        {
          name: 'jcorddion',
          description: 'jQuery acorddion plugin.',
          url: 'http://gillchristian.github.io/jcorddion/',
          img: 'assets/img/portfolio/jcorddion.jpg',
          tags: ['jQuery','plugin', 'accordion', 'bower-package']
        },
        {
          name: 'Tii',
          description: 'Simple JavaScript assertion library.',
          url: 'http://npmjs.org/package/tii/',
          img: 'assets/img/portfolio/tii.jpg',
          tags: ['npm-package','tests', 'library', 'ES6']
        },
        {
          name: 'CPT Class',
          description: 'Helper class to create Custom Pots Types in WordPress.',
          url: 'https://github.com/gillchristian/CPT',
          img: 'assets/img/portfolio/cpt.jpg',
          tags: ['WordPress','php']
        },
        {
          name: 'Army Calculator',
          description: 'Troops amounts and costs calculator for Clash of Clans.',
          url: 'http://gillchristian.github.io/clash/',
          img: 'assets/img/portfolio/clash_app.jpg',
          tags: ['angularJS','bootstrap']
        },
      ];
    }
]);