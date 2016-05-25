<div id="header">
		<a id="imageBanner" href="index.php" class="logo">
			<img src="images/logo.png" alt="TailWagz logo">
		</a>
		<div id="authBanner">
			<p class="auth" id="username"><?php 
			if (isset($_SESSION['username']))
			{
				echo "You are logged in as <b>";
				echo $_SESSION['username'];
			} else {
				//echo 'Not logged in';
			}
		?></b></p>
		<?php
				if (isset($_SESSION['isLoggedOn']))
				{
					?><a class="auth" href="logout.php">Log Out</a><?php	
				} else {
					?><a class="auth" href="login.php">Log In</a>
					<a class="auth" href="signup.php">Sign Up</a>
					<?php
				}
			?></div>
		
		<!--<ul id="navigationBanner">
			<li>
				<a href="index.php">home</a>
			</li>
			<li>
				<a href="search.php">search</a>
			</li>
			<li>
				<a href="results.php">results</a>
			</li>
			<li>
				<a href="item.php">single item</a>
			</li>
		</ul>-->
	</div>