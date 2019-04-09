#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> article, word, ans;
	set<string> s;
	map<string, bool> vis;
	FILE *fp;  //读取文章
	if((fp = fopen("article.txt", "r")) == NULL)
	   printf("Cannot open file\n");
    while(!feof(fp)){
    	char strLine[512] = {0};
    	fgets(strLine,sizeof(strLine), fp);
    	const char *d = " ";
    	char *p = strtok(strLine, d); //以空格进行分割
    	while(p){
    		string temp = p;
    		transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    		//cout<< temp <<endl;
    		article.push_back(temp);
    		p = strtok(NULL, d);
		}
	}
	fclose(fp);
	//for(int i=0;i<article.size();i++)
	//	printf("%s\n",article[i].c_str());

	if((fp = fopen("word.txt", "r")) == NULL) //读取单词表
	   printf("Cannot open file\n");
    while(!feof(fp)){
    	char strLine[512] = {0};
    	fgets(strLine,sizeof(strLine), fp);
        const char *d ="\n";
        char *p = strtok(strLine,d); //以空格进行分割
        while(p){
           string temp = strLine;
           transform(temp.begin(),temp.end(),temp.begin(),::tolower);
		   word.push_back(temp);
		   p = strtok(NULL, d);
		}
	}
	fclose(fp);
	//for(int i=0;i<word.size();i++){
	//	printf("%s\n", word[i].c_str());
	//}
    for(int i=0;i<word.size();i++)
    	s.insert(word[i]);

	for(int i=0;i<article.size();i++){
		if(s.count(article[i]) && !vis[article[i]] ){
			ans.push_back(article[i]);
			printf("%s\n",article[i].c_str());
			vis[article[i]] = true;
		}
	}

	if((fp = fopen("output.txt","w")) == NULL) //存储结果
	    printf("Cannot open file\n");
	for(int i=0;i<ans.size();i++){
		fprintf(fp,"%s\n",ans[i].c_str());
	}
	fclose(fp);
	system("pause");
	return 0;
}
