jQuery(function () {
	(function ($) {
		// render LaTex with  KaTex if the boswer not IE 8 / 7 / 6
		if ($('html').hasClass('ie8') || $('html').hasClass('ie7')) {
			MathJax.Hub.Config({
				tex2jax: {inlineMath: [['$', '$']]},
				messageStyle: "none"
			});
			$.getScript("//cdn.bootcss.com/mathjax/2.5.3/MathJax.js?config=TeX-AMS-MML_HTMLorMML");
		} else {
			renderMathInElement(document.body, {
				delimiters: [{left: '\\[', right: '\\]', display: false}, {left: '$', right: '$', display: false}, {left: '\\(', right: '\\)', display: true}, {left: '$$', right: '$$', display: true}]
			});
		}
		// setup markdown highlight handler
		//marked.setOptions({
		//	highlight: function (code) {
		//		return hljs.highlightAuto(code).value;
		//	}
		//});
		// render markdown with marked.js
		$('.markdown').each(function(index, md) {
			var self = $(this);
			self.html(marked(self.html().trim())).addClass('marked');
			if (typeof hljs == 'object') {
				$('[class*="lang-"]').each(function () {
					hljs.highlightBlock(this);
				});
			}
		});
	})(jQuery);
});
