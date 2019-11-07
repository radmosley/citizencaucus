<template>
<div id="code">
  <navbar>
  </navbar>
  <Sidebar>
  </Sidebar>
</div>
</template>

<script>
import Navbar from './components/Navbar.vue'
import Sidebar from './components/Sidebar.vue'


export default {
  name: 'app',
  components: {
    Navbar,
    Sidebar
  }
}
</script>

<style lang="scss">
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
body {
  margin:0;
  padding:0;
}
</style>
