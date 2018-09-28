<?php
include_once 'blade/view.VideoReply.blade.inc';
include_once 'blade/view.VideoComment.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';
?>

<div class="panel panel-default"> <?php //1st div >  ?>
				
	 <div class="panel-heading">Video Tutorial Viewer</div>  <?php // 2nd div >  ?>

	 			
	 <div  style="overflow: auto;padding: -100px 100px;  >  <?php //3rd div >  ?>
	 	 <div id="video">  <?php //4th div >  ?>


	 	 		

	 	 	<?php
				$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
				$Video2 = substr($id, -38);
				$Result1 = $_VideoCommentBAO->readvideo($Video2);
				//if DAO access is successful to load all the comments then show them one by one
				if($Result1->getIsSuccess()){ // 1st if start 
				$Vedio = $Result1->getResultObject();
			?> 
			<div>
              	<label class="control-label"><?php echo $Vedio->getTitle(); ?></label>
			</div>
			<div>
				<?php
					$front = '<iframe width="560" height="315" src="https://www.youtube.com/embed/' ;
					$back = '" frameborder="0" allowfullscreen></iframe>';
					$link = $Vedio->getLink();
					//$link2= substr($link);
					$Link=$front.$link.$back;
					echo $Link; 
				?>
			</div>
			<?php
				}
				else{
				echo $Result->getResultObject(); //giving failure message //1st if close 
				}
			?>
		</br>
					playlist 
				<div style ="padding: 25px 0px;"> <!--Playlist--->
					<iframe width="144" height="100"
						src="https://www.youtube.com/embed/tgbNymZ7vqY">
					</iframe>
				</div> <!--End of pLaylist ---> 
					 
					<div style ="padding: 25px 250px;"> <!--Playlist--->
					<iframe width="144" height="100"
						src="https://www.youtube.com/embed/tgbNymZ7vqY">
					</iframe>
				</div> <!--End of pLaylist ---> 
				<div style ="padding: 25px 500px;"> <!--Playlist--->
					<iframe width="144" height="100"
						src="https://www.youtube.com/embed/tgbNymZ7vqY">
					</iframe>
				</div> <!--End of pLaylist ---> 

		</div> <?Php // 4th div close  // video div end comment box start ; //comment correction 17-09?>

		<div> <?php //1st cmnt post box div > ?>
		 	<form method="post" class="panel panel-info" >
		 		<input type='text' name ="txtvideo" value="<?php echo $Video2 ; ?>" placeholder="<?php echo $Video2 ; ?>"" style="display : none" />
		 		<div class="panel-heading">Add a public comment</div>
		 		<div class="panel-body">
					<textarea class="form-control" name="txtAns" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getComment();  ?>" >
					</textarea>
					</br>
					<input class="btn btn-success btn-lg"  type="submit" id="savebutton"  name="save" value="Submit">
				</div>
			</form>
		</div> <?php //1st cmnt post box end ?>
		<div class="panel panel-success"> <?php // rc div 1 ?>
      		<div class="panel-heading">Recent comments</div> 
		</div>  <?php // rc div 1 end ?>

		<?php 
			//all comment fetch 
			$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
			$Video2 = substr($id, -38);
			//echo $Video2;	
			$Result1 = $_VideoCommentBAO->readVideoComment($Video2);
			//if DAO access is successful to load all the comments then show them one by one
			if($Result1->getIsSuccess()){
				$VideoList = $Result1->getResultObject();
						for($i = 0; $i < sizeof($VideoList); $i++) {
							$Video = $VideoList[$i];
							if($i%2==0){
		?> 
		<div class="panel panel-danger" style="border-style:solid;background-color: white">
		<?php
										}
		else{ 
		?>
			<div class="panel panel-danger" style="border-style:solid;background-color: white">

		<?php 
		//upore div er oita 2 bar silo , 1bar kore disi
			}
		?>								
				<div class="panel-heading" style="font-size:12px;font-weight:bold ;position: relative; left: 0px; width:545px;">						

		<?php 
			$id= $Video->getCreator();
			$Result5 = $_VideoCommentBAO->readCreator($id);
			if ($Result5->getIsSuccess()) {
				$user = $Result5->getResultObject();
				echo $user->getFirstName().' '.$user->getLastName().'';
							    			} 
		?>		</div>
				<div style ="position: relative; left: 10px; width:1000px;"  class="panel panel-danger">
					<?php echo $Video->getComment();
					//calss.common.forum.inc er last a ase  
					?>
				</div>

				<div style ="position: relative; left: 50px; width:500px;font-weight:bold ;"  class="panel-heading">Md Rakibul Hasan Molla</div> 
									<div style ="position: relative; left: 50px; width:970px;"  class="panel panel-danger">Thank you sir </div> 

									<div style ="position: relative; left: 50px; width:500px;font-weight:bold ;"  class="panel-heading">Tamim Iqbal </div> 
									<div style ="position: relative; left: 50px; width:970px;"  class="panel panel-danger">This is a test reply  </div>
		
						<?php		

							} // comment for loop end

							} // comment sucess if end 
							else
							{
								echo $Result->getResultObject();
							}


						
								?>
									 


		</div> <?php //comment box er div ?>



		</div>
</div>  <?php //panel body er div ?>

</div> <?php //last panel er div ?> 