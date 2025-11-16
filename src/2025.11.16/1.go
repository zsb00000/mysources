package main

import "fmt"

var n,m int
var _map [1005][1005]int
var father [(int)(1e6+5)]int
var vis [1005][1005]bool
var dx =[4]int{0,1,0,-1}
var dy =[4]int{1,0,-1,0}
var rank [(int)(1e6+5)]int

func get(x,y int) int{
	return (x-1)*n+y
}

func find(x int) int{
	if father[x]==x{
		return x
	}
	father[x]=find(father[x])
	return father[x]
}

func union(x,y int) {
	var rx int=find(x)
	var ry int=find(y) 

	if rank[rx]<rank[ry]{
		father[rx]=ry
		rank[ry]+=rank[rx]
	} else {
		father[ry]=rx
		rank[rx]+=rank[ry]
	}
}

func dfs(x,y int) {
	// fmt.Printf("Visiting: (%d, %d) = %d\n", x, y, _map[x][y])
	for i:=0;i<4;i++{
		xx :=x+dx[i]
		yy :=y+dy[i]
		// fmt.Printf("Checking neighbor: (%d, %d)\n", xx, yy)
		if !(xx>=1&&xx<=n&&yy>=1&&yy<=n){
			continue
		}
		if (_map[xx][yy] == _map[x][y]) {
			continue
		}
		if vis[xx][yy]{
			continue
		}
		vis[xx][yy] = true
		var a int = get(x,y)
		var b int = get(xx,yy)
		union(a,b)
		dfs(xx,yy)
	}
}

func main(){
	fmt.Scan(&n,&m)
    for i := 1; i <= n; i++ {
        var s string
        fmt.Scan(&s)
        for j := 1; j <= n; j++ {
            _map[i][j] = int(s[j-1] - '0')
        }
    }
	for i:=1;i<=n*n;i++{
		father[i]=i
		rank[i]=1;
	}
	for i:=1;i<=n;i++{
		for j:=1;j<=n;j++{
			if !vis[i][j]{
				vis[i][j]=true
				dfs(i,j)
			}
		}
	}
	for i:=1;i<=m;i++{
		var x,y int
		fmt.Scan(&x,&y)
		fmt.Println(rank[find(get(x,y))])
	}
}
/*
2 0
01
10
*/