
		<html>
			<head>
				<title>Updater</title>
				<meta charset="UTF-8">
				<style>
					html {
						padding: 50px 10px;
						font-size: 16px;
						line-height: 1.4;
						color: #666;
						background: #F6F6F3;
						-webkit-text-size-adjust: 100%;
						-ms-text-size-adjust: 100%;
					}

					html,
					input { font-family: "Helvetica Neue", Helvetica, Arial, sans-serif; }
					body {
						max-width: 500px;
						max-height: 30px;
						padding: 30px 20px;
						margin: 0 auto;
						background: #FFF;
					}
					ul {
						padding: 0 0 0 40px;
					}
					.container {
						max-width: 380px;
						_width: 380px;
						margin: 0 auto;
					}
				</style>
			</head>
			<body>
				<div class="container">
				<?php
				function getJsonRequest($url){
					$ch = curl_init();
					curl_setopt($ch, CURLOPT_URL, $url);
					curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
					curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);
					curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
					$output = curl_exec($ch);
					curl_close($ch);
					$output = json_decode($output,true);
					return $output;
				}
				function deldir($dir) {
					$dh=opendir($dir);
					while ($file=readdir($dh)) {
						if($file!="." && $file!="..") {
							$fullpath=$dir."/".$file;
							if(!is_dir($fullpath)) {
								unlink($fullpath);
							} else {
								deldir($fullpath);
							}
						}
					}
					closedir($dh);
					if(rmdir($dir)) {
						return true;
					} else {
						return false;
					}
				}
				function getRequest($url){
					$ch = curl_init();
					curl_setopt($ch, CURLOPT_URL, $url);
					curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
					curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);
					curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
					$output = curl_exec($ch);
					curl_close($ch);
					return $output;
				}
				$dir = "../usr/themes/Bubble";

				try{
					$version = getJsonRequest("https://data.jsdelivr.com/v1/package/resolve/gh/trinitrotofu/Bubble")["version"];
					$files = getJsonRequest("https://data.jsdelivr.com/v1/package/gh/trinitrotofu/Bubble@" . $version . "/flat")["files"];
					if(file_exists($dir)) deldir($dir);

					foreach ($files as $key => $value){
						$filecontent = getRequest("https://cdn.jsdelivr.net/gh/trinitrotofu/Bubble@" . $version . "/" .$value["name"]);
						if (!file_exists(dirname($dir.$value["name"]))){
							mkdir(dirname($dir.$value["name"]),0755,true);
						}
						$fileobj = fopen($dir.$value["name"], "w");
						fwrite($fileobj, $filecontent);
						fclose($fileobj);
					}
					
					echo "主题更新成功！即将返回主题页面。";
					echo '<meta http-equiv="refresh" content="3;url=themes.php">';
					@unlink ("themeupdater.php");  
				}catch(Exception $e){
					echo "更新失败！请查看错误信息或者手动更新。<br>";
					echo $e;
				}
				?>
				</div>
			</body>
		</html>