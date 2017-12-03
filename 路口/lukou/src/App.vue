<template>
  <div id="app">
    <router-view :data="data"></router-view>
    <div class="tab">
      <div class="tab-item">
        <router-link to="/jingxuan"><div class="content"><i class="iconfont icon-jingxuan"></i><span class="text">精选</span></div></router-link>
      </div>
      <div class="tab-item">
        <router-link to="/faxian"><div class="content"><i class="iconfont icon-faxian-copy"></i><span class="text">发现</span></div></router-link>
      </div>
      <div class="tab-item">
        <router-link to="/myquan"><div class="content"><i class="iconfont icon-ren"></i><span class="text">路友圈</span></div></router-link>
      </div>
      <div class="tab-item">
        <router-link to="/me"><div class="content"><i class="iconfont icon-icons-nvxingyonghu" ></i><span class="text">我的</span></div></router-link>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'app',
  data () {
    return {
      data: {}
    }
  },
  created() {
    this.$axios.get('/api/data')
    .then((res) => {
      res = res.data
      if(res.error === 0) {
        this.data =res.data
      }
      })
      .catch((error) => {
      alert(error)
      })

  }
}
</script>

<style lang="less">
#app {
  .tab{
    position: absolute;
    bottom: 0;
    display: flex;
    height: 57px;
    border-top: 1px solid #ccc;
    width: 100%;
    .tab-item{
      flex: 1;
      text-align: center;
      & > a {
        display: block;
        color: rgb(77, 85, 93);
        .content{
          height: 57px;
          height-line:57px;
          padding-top: 4px;
          box-sizing: border-box;
          .iconfont{
            display: block;
            font-size: 28px;
          }
          .text{
            margin-top: 4px;
            display: block;
            font-size:12px;
          }
        }
        &.active {
          color: #c76686;
        }
      }
    }
  }

}
</style>
