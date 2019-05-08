<template>
  <div id="app">
    <NavBar />
    <SideBar />
    <Content />
  </div>
</template>

<script>
import NavBar from './components/NavBar.vue'
import SideBar from './components/SideBar.vue'
import Content from './components/Content.vue'
import ListIcon from './components/ListIcon.vue'
import { library } from '@fortawesome/fontawesome-svg-core'
import { faCoffee } from '@fortawesome/free-solid-svg-icons'
import { FontAwesomeIcon } from '@fortawesome/vue-fontawesome'

export default {
  name: 'app',
  components: {
    NavBar,
    SideBar,
    Content
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

body {
    padding:0;
    margin:0;
}

h1 {
        margin: 1vh 0;
}
</style>
