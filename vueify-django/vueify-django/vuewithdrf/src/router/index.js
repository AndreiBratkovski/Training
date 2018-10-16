import Vue from 'vue'
import Router from 'vue-router'
import Home from '../views/Home'
import Cat from '../views/Cat'

Vue.use(Router)
export default new Router({
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home
    },
    {
      path: '/cat',
      name: 'cat',
      component: Cat
    }
  ]
})