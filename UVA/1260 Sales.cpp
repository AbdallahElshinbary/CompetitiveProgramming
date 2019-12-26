<!DOCTYPE html>
<!-- comment -->
<html lang="en" xml:lang="en">
<head>
	<meta charset="UTF-8" />
	<!-- node ideone-www2 -->
		<title>Online Compiler and IDE &gt;&gt; C/C++, Java, PHP, Python, Perl and 70+ other compilers and interpreters - Ideone.com</title>
		<meta name="description" content="Compile various programming languages online. Add input stream, save output, add notes and tags." />	
		<meta name="keywords" content="online compiler, online ide, learn programming online, programming online, run code online, snippet, snippets, pastebin, online debugging tool, online interpreter, run your code online, run code, execute code, C++, Java, Python" />
	<meta property="og:site_name" content="Ideone.com"/>
	<meta property="og:image" content="http://profile.ak.fbcdn.net/hprofile-ak-prn1/50232_245768360841_3377786_q.jpg"/>
	<meta property="og:description" content="Ideone is something more than a pastebin; it's an online compiler and debugging tool which allows to compile and run code online in more than 40 programming languages."/>
	<meta property="og:title" content="Ideone.com"/>
	<link rel="shortcut icon" type="image/png" href="//stx1.ideone.com/gfx2/img/favicon.png" />
			
				<link href="//stx1.ideone.com/gfx2/libs/bootstrap/css/bootstrap-with-responsive-1200-only.min.css" rel="stylesheet" media="all"/>
				
		 
		<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
		<!-- , initial-scale=0.25 -->
		
	
	
	
	
	<link rel="preconnect" href="https://www.google-analytics.com">
	<link rel="preconnect" href="https://srv.carbonads.net">
	<link rel="preconnect" href="https://srv.buysellads.com">
	<link rel="preconnect" href="https://vc.hotjar.io">
	<link rel="preconnect" href="https://vars.hotjar.com">
	
	
	<style>
	[class^="icon-"], [class*=" icon-"] {
		display: inline;
		width: auto;
		height: auto;
		/*line-height: normal;*/
		vertical-align: baseline;
		background-image: none;
		background-position: 0% 0%;
		background-repeat: repeat;
		margin-top: 0;
	}
	a [class^="icon-"], a [class*=" icon-"] {
		display: inline;
	}
	</style>
	
	
	<link href="//stx1.ideone.com/gfx2/libs/fontello-8f7d2dfe/css/fontello.css?3" rel="stylesheet"/>
	<!--[if IE 7]>
		<link rel="stylesheet" href="//stx1.ideone.com/gfx2/libs/fontello-8f7d2dfe/css/fontello-ie7.min.css?3">
	<![endif]-->
	
	
	<link href="//stx1.ideone.com/themes/smoothness/jquery-ui-1.10.1.custom.min.css" type="text/css" rel="stylesheet"/> <!-- jak sie wrzuci do bundle to nie dziala -->
	<!-- <link href="/gfx2/css/jquery-ui-bootstrap/jquery-ui-1.10.0.custom.css" type="text/css" rel="stylesheet" /> --> <!-- mozna ew wlaczyc zamiast tego powyzej -->
		
	<!-- 2013-02-07 by wiele: na czas develu wyrzucam to z bundle zeby moc latwiej debugowac w firebugu -->
	
	
	
	<link href="//stx1.ideone.com/gfx2/css/ideone-bundle.css?3" rel="stylesheet"/>
	<!-- end of rzeczy przeniesione tymczasowo z bundle -->
	
	
	
	
	
	<script type="text/javascript">
	
		var cookie_name = 'settings';
		var cookie_time = 15552000;
		var is_mobile = 0;
		
		
				var ace_options = {};
			</script>
	
	<!-- 2013-02-07 by wiele: na czas develu wyrzucam to z bundle zeby moc latwiej debugowac w firebugu -->
	
	
	
	
	
	<script type="text/javascript" src="//stx1.ideone.com/gfx2/js/ideone-libs-bundle.js?2"></script>
	<script type="text/javascript" src="//stx1.ideone.com/gfx2/libs/ace-2017-06/ace.js?1" data-ace-base="/gfx2/libs/ace-2017-06"></script>
	<script type="text/javascript" src="//stx1.ideone.com/gfx2/js/ideone-common.js?12"></script>
	<!-- end of rzeczy przeniesione tymczasowo z bundle -->
	
</head>


<body class="  not-responsive">
	<div id="_container">
<noscript><div id="js_required" class="alert alert-error" style="margin-bottom: 0px">Ideone.com requires JavaScript to work.</div></noscript>
<div class="navbar " id="primary-navigation">
	<div class="navbar-inner">
		<div class="container">
			<a class="btn btn-navbar collapsed" data-toggle="collapse" data-target=".nav-collapse">
				<span class="icon-bar"></span> 
				<span class="icon-bar"></span> 
				<span class="icon-bar"></span> 
			</a>
						<a href="/" class="brand scroll-page"><span></span></a>
						<div class="nav-collapse collapse " style="height: 0px;">
				
				<ul class="nav pull-right">
										<li class=""><a href="/"  class="scroll-page"><i class="icon-home"></i> new code</a></li>
										<li class=""><a href="/samples"  class="scroll-page"><i class="icon-lightbulb"></i> samples</a></li>
					<li class=""><a href="/recent"  class="scroll-page"><i class="icon-cloud"></i> recent codes</a></li>
															<li class="dropdown">
						<a href="#"  class="dropdown-toggle btn-singin-wnd-open" data-toggle="dropdown"><i class="icon-signin"></i> sign in</a>
						<ul class="dropdown-menu dropdown-form" id="signin-dropdown">
                        <li class="dropdown-caret right">
                          <span class="caret-outer"></span>
                          <span class="caret-inner"></span>
                        </li>
                        <li>
                          <div class="modal-body">
					    	<form action="//ideone.com/account/login" method="post">
												    		<div style="margin-bottom: 20px;">
									New user? <a class="normal-link"  href="/account/register">Sign up</a>
								</div>
																
								<div class="control-group">
									<div class="controls">
										<div class="input-prepend" style="margin-bottom: 0px">
											<span class="add-on rel-tooltip" title="Username or e-mail"><i class="icon-user"></i></span>
											<input type="text" class="span2" id="username" name="username" value="" placeholder="Username or e-mail" />
										</div>
									</div>
								</div>
					    		
					    		<div class="control-group" style="margin-bottom: 0px">
					    			<div class="controls">
					    				<div class="input-prepend">
					    					<span class="add-on rel-tooltip" title="Password"><i class="icon-key"></i></span>
					    					<input type="password" class="span2" id="password" name="password" value="" placeholder="Password" />			
					    				</div>
					    			</div>
					    		</div>
					
								<input type="hidden" name="remember" value="yes"/>
								<input type="hidden" name="next" value="LzZwbGFpbi9pT0dZWQ=="/>
								
								<div class="control-group">
									<div class="controls">
										<button type="submit" class="btn"><i class="icon-signin"></i> Sign in</button>
									</div>
								</div>
								
								<div>
									<a class="normal-link" href="/account/forgot">Can't sign in?</a>
								</div>
								
																<hr class="clear" style="margin: 0px; margin-bottom: 10px"/>
								<a class="btn facebook-login-button" href="https://www.facebook.com/dialog/oauth?client_id=347515280067&redirect_uri=https://ideone.com/account/registerfb/&scope=email,user_location,user_hometown">Log in with Facebook</a>
															</form>
					  </div>
                	</li>
                      </ul>
					</li>
															
					<li class=" dropdown-hover">
					
					</li>
					
									</ul>
			</div>
			<!-- /.nav-collapse --> 
		</div>
		<!-- /.container --> 
	</div>
	<!-- /.navbar-inner --> 
</div>

<div class="container" style="padding: 0; margin-top: 0; margin-bottom: 0;">

</div>


<div class="container">
	<div class="row">
		<div class="span12">
		<h3>Page not found.</h3>
		</div>
	</div>
</div>

		
				
			<div id="footer" class="footer shadow-inner-top">
				<div class="container">
									<a href="http://sphere-research.com?utm_campaign=permanent&utm_medium=footer&utm_source=ideone" target="_blank">Sphere Research Labs</a>.
					Ideone is powered by <a href="http://sphere-engine.com/?utm_campaign=permanent&utm_medium=footer&utm_source=ideone" target="_blank">Sphere Engine&trade;</a>
								
				<p id="footer-links">
					<a href="/">Home</a>
					
					<a href="https://sphere-engine.com/?utm_campaign=permanent&utm_medium=sphereengine&utm_source=ideone" target="_blank">API</a>
					
											<a href="#" data-toggle="modal" data-target="#lang-dialog">Language</a>  
										<a href="/faq">FAQ</a>
					<a href="/credits">Credits</a>
					
					
										<span style="margin-left: 20px">
													desktop
				 			<a href="/switch/mobile/LzZwbGFpbi9pT0dZWQ==" class="margin-left">mobile</a>
									 		</span>
			 		<br/>
			 		<a href="/legal-tos">Terms of Service</a>
			 		<a href="/legal-pp">Privacy Policy</a>
			 		<a href="/legal-gdpr">GDPR Info</a>
				</p>
				
				<a href="/ideone/Tools/bug/form/1" id="show_bug_dialog" data-toggle="modal" data-target="#bug-dialog">Feedback &amp; Bugs</a>
					
				<!-- 
				<p class="values">4, 0.01s, 0.03s</p>
				-->
				
				<br>
			    <p><strong>Popular languages:</strong></p>
			    <p>
			         <a href="/l/bash">Bash</a>
                     <a href="/l/pascal">Pascal</a>
                     <a href="/l/c">C</a>
                     <a href="/l/perl">Perl</a>
                     <a href="/l/c-sharp">C#</a>
                     <a href="/l/php">PHP</a>
                     <a href="/l/cpp">C++</a>
                     <a href="/l/pascal">Python</a>
                     <a href="/l/cpp14">C++14</a>
                     <a href="/l/python-3">Python3</a>
                     <a href="/l/haskell">Haskell</a>
                     <a href="/l/ruby">Ruby</a>
                     <a href="/l/java">Java</a>
                     <a href="/l/sqlite">SQLite</a>
                     <a href="/l/objective-c">Objective-C</a>
                     <a href="/l/swift">Swift</a>
                     <a href="/l/vb-net">VB.net</a>
                     <br/>
                     <a href="/languages">List of all supported programming languages</a>
			    </p>
				
				</div>
			</div>
						
			
			
<div class="modal hide fade" id="bug-dialog" role="dialog" tabindex="-1">
  <div class="modal-header">
    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
    <h3>Report bug / make suggestion</h3>
  </div>
  <div class="modal-body">
	<img src="//stx1.ideone.com/gfx/loader.gif" style="width: 14px; height: 14px;" alt="loading..."/>
  </div>
  <div class="modal-footer">
    <a href="#" class="btn" data-dismiss="modal">Close</a>
    <a href="#" class="btn btn-primary" id="bug-dialog-submit">submit</a>
  </div>
</div>


<div class="modal hide fade" id="lang-dialog">
	<div class="modal-header">
    	<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
    	<h3>Choose your language</h3>
	</div>
	<div class="modal-body">
		<ul style="list-style-type: none;">
			<li><a href="/lang/en"><b>English</b></a></li>
			<li><a href="/lang/hi">Hindi</a></li>
			<li><a href="/lang/hu">Hungarian</a></li>
			<li><a href="/lang/mn">Mongolian</a></li>
			<li><a href="/lang/pl">Polish</a></li>
			<li><a href="/lang/ru">Russian</a></li>
			<li><a href="/lang/es">Spanish</a></li>
			<li><a href="/lang/zh">Traditional Chinese</a></li>
					</ul>
		
	</div>
  <div class="modal-footer">
    <a href="#" class="btn" data-dismiss="modal">close</a>
  </div>
</div>



<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
  ga('create', 'UA-10507872-8', 'auto');
  ga('send', 'pageview');
</script>
<script type="text/javascript">
$(function(){
	$(document).on('click', '.track', function(){
		var event = $(this).attr('data-event');
		var action = $(this).attr('data-action');
		var value = $(this).attr('data-value');
		ga('send', 'event', event, action, value);
		console.log(event);
	});
});
</script>
<!-- Hotjar Tracking Code for http://ideone.com -->
<script>
    (function(h,o,t,j,a,r){
        h.hj=h.hj||function(){(h.hj.q=h.hj.q||[]).push(arguments)};
        h._hjSettings={hjid:334655,hjsv:5};
        a=o.getElementsByTagName('head')[0];
        r=o.createElement('script');r.async=1;
        r.src=t+h._hjSettings.hjid+j+h._hjSettings.hjsv;
        a.appendChild(r);
    })(window,document,'//static.hotjar.com/c/hotjar-','.js?sv=');
</script>

<script>
</script>


<script src="//m.servedby-buysellads.com/monetization.js" type="text/javascript"></script>
<script>
(function(){
		if(typeof _bsa !== 'undefined' && _bsa) {
			  		// format, zoneKey, segment:value, options
			  		_bsa.init('flexbar', 'CK7D4KJJ', 'placement:ideonecom');
					  	}
})();
</script>


		</div><!-- end of #_container -->


<!--
<script type="text/javascript">
(function() {
        var wrc = document.createElement('script'); wrc.type = 'text/javascript'; wrc.async = true; window.rc_utm_source='ideone';
        wrc.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'recruitcoders.com/w4loader.js';
        var s = document.getElementsByTagName('body')[0]; s.appendChild(wrc);
})();
</script>
-->


	</body>
</html>
