<template>

<div id=Navbar>
    <div id="container">
        <Branding> </Branding>
        <Search></Search>
    </div>
</div>

</template>

<script>
import Branding from './Branding.vue'
import Search from './Search.vue'

export default {
  name: 'app',
  components: {
    Branding,
    Search
  }
}
</script>

<style scoped>
h1 {
        color: white;
        margin: 0;
    }
a {
        text-decoration: none;
    }

#Navbar {
    background-color: black;
    height: 10%;
    width: 100%;

}

#container {
    width:80%;
    margin: auto;
    display: flex;
    justify-content: space-between;
}

#branding {
    display: block;
}
#search {
    display: block;
}
</style>