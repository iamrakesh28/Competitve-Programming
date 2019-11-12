if (self.CavalryLogger) { CavalryLogger.start_js(["c1DTw"]); }

__d("PhotoStoreCore",[],(function(a,b,c,d,e,f){__p&&__p();var g={actions:{UPDATE:"update"},_photoCache:{},_postCreateCallbacks:{},getPhotoCache:function(a){if(!this._photoCache[a])throw new Error("Photo cache requested for unknown set ID");return this._photoCache[a]},hasBeenCreated:function(a){return!!this._photoCache[a]},clearSetCache:function(a){delete this._photoCache[a],delete this._postCreateCallbacks[a]},getByIndex:function(a,b,c){this.getPhotoCache(a).getItemAtIndex(b,c)},getByIndexImmediate:function(a,b){return this._photoCache[a]?this._photoCache[a].getItemAtIndexImmediate(b):void 0},getItemsInAvailableRange:function(a){var b=this.getAvailableRange(a),c=[];for(var d=b.offset;d<b.length;d++)c.push(this.getByIndexImmediate(a,d));return c},getItemsAfterIndex:function(a,b,c,d){b=this.getCursorByIndexImmediate(a,b);this.fetchForward(a,b,c,d)},getAllByIDImmediate:function(a){var b=this,c=Object.keys(this._photoCache);return c.map(function(c){return b.getByIndexImmediate(c,b.getIndexForID(c,a))}).filter(function(a){return!!a})},getIndexForID:function(a,b){return this._photoCache[a]?this._photoCache[a].getIndexForID(b):void 0},getEndIndex:function(a){a=this.getAvailableRange(a);return a.offset+a.length-1},getCursorByIndexImmediate:function(a,b){b=this.getByIndexImmediate(a,b);return b?this._photoCache[a].getCursorForID(b.id):void 0},hasNextPage:function(a){var b=this.getCursorByIndexImmediate(a,this.getEndIndex(a));return this.getPhotoCache(a).hasNextPage(b)},getAvailableRange:function(a){return this.getPhotoCache(a).getAvailableRange()},hasLooped:function(a){return this.getPhotoCache(a).hasLooped()},fetchForward:function(a,b,c,d){this.getPhotoCache(a).getItemsAfterCursor(b,c,d)},fetchBackward:function(a,b,c,d){this.getPhotoCache(a).getItemsBeforeCursor(b,c,d)},executePostCreate:function(a,b){this._photoCache[a]?b&&b():this._postCreateCallbacks[a]=b},runPostCreateCallback:function(a){var b=this._postCreateCallbacks[a];b&&(b(),delete this._postCreateCallbacks[a])},setPreFetchCallback:function(a,b){this.getPhotoCache(a).setPreFetchCallback(b)},updateData:function(a){var b=a.set_id;!this._photoCache[b]?(this._photoCache[b]=new a.cache_class(a),this.runPostCreateCallback(b)):a.query_metadata.action==g.actions.UPDATE?this._photoCache[b].updateData(a):this._photoCache[b].addData(a)},updateFeedbackData:function(a){var b=Object.keys(a);b.forEach(function(b){return g.getAllByIDImmediate(b).forEach(function(c){c.feedback=a[b].feedback})})},reset:function(){var a=this;Object.keys(this._photoCache).forEach(function(b){return a.clearSetCache(b)})}};e.exports=g}),null);
__d("PhotoStore",["Arbiter","PhotoStoreCore"],(function(a,b,c,d,e,f){b("Arbiter").subscribe("update-photos",function(a,c){b("PhotoStoreCore").updateData(c)}),e.exports=b("PhotoStoreCore")}),null);
__d("ContextualLayerHideOnScrollOut",["Event","SubscriptionsHandler"],(function(a,b,c,d,e,f){__p&&__p();a=function(){"use strict";__p&&__p();function a(a){this.$1=a}var c=a.prototype;c.enable=function(){this.$4==null&&(this.$4=new(b("SubscriptionsHandler"))(),this.$4.addSubscriptions(this.$1.subscribe("contextchange",this.$5.bind(this)),this.$1.subscribe("show",this.$6.bind(this)),this.$1.subscribe("hide",this.$7.bind(this))))};c.disable=function(){this.$4!=null&&(this.$4.release(),this.$4=null),this.$7()};c.$6=function(){if(this.$2==null){this.$3=this.$1.getContextScrollParent();if(this.$3===window)return;this.$2=b("Event").listen(this.$3,"scroll",this.$8.bind(this))}};c.$7=function(){this.$2&&(this.$2.remove(),this.$2=null,this.$3=null)};c.$8=function(){var a=this.$3,b=this.$1;if(a==null||b==null)return;var c=b.getContent().getBoundingClientRect();a=a.getBoundingClientRect();var d=c.bottom<=a.top||c.top>=a.bottom;c=c.right<=a.left||c.left>=a.right;(d||c)&&b.hide()};c.$5=function(){this.detach!==null&&this.detach(),this.attach!=null&&this.$1.isShown()&&this.attach()};return a}();e.exports=a}),null);
__d("codedError",["fbt","invariant"],(function(a,b,c,d,e,f,g,h){"use strict";__p&&__p();function a(a){h(0,2095)}a.withParams=function(a,b){h(0,2095)};a._=function(a,b,c,d){b=b(g);c=c(g,d);d=b+": "+c;d=new Error(d);Object.assign(d,{framesToPop:1,code:a,description:c,summary:b});return d};e.exports=a}),null);
__d("FRXEntryPoint",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({AGORA_GROUPS:"agora_groups",AGORA_RECENT_NEWS:"agora_recent_news",BLOCK_BUTTON:"block_button",BLOCK_COMPOSER:"block_composer",CHEVRON_BUTTON:"chevron_button",CHEVRON_TAGS:"chevron_tags",CONTENT_OVERLAY:"content_overlay",COMMENT:"comment",DEVELOPER_FEEDBACK_BUTTON:"developer_feedback_button",EVENTS_REPORTING:"events_reporting",FEEDBACK_BUTTON:"feedback_button",FOX_CHEVRON_TAGS:"fox_chevron_tags",GEMSTONE_MEDIA:"gemstone_media",GEMSTONE_MESSAGING:"gemstone_messaging",GEMSTONE_PROFILE:"gemstone_profile",GROUPS_ADMIN_FEEDBACK:"groups_admin_feedback",GROUPS_DISCOVER:"groups_discover_page",GROUPS_DISCOVER_HIDE_BUTTON:"groups_discover_hide_button",GROUPS_JOIN_QUESTION:"groups_join_question",GROUPS_LEAVE:"groups_leave",GROUPS_LEAVE_BROWSE:"groups_leave_browse",GROUPS_LEAVE_SPECIAL:"groups_leave_special",GROUP_MALL_RELATED_GROUPS_CHAINING:"group_mall_related_groups_chaining",GROUP_MALL_RHC:"group_mall_rhc",GROUPS_POLL:"groups_poll",GROUPS_REPORT:"groups_report",GROUPS_REPORT_TO_ADMIN:"groups_report_to_admin",GROUPS_TAB_CHAT_ROW:"groups_tab_chat_row",GROUPS_TAB_DISCOVER_FIRST:"groups_tab_discover_first",HATE_CTA:"hate_cta",HIDE_AD_BUTTON:"hide_ad_button",MARK_AS_SOLD_BUTTON:"mark_as_sold_button",MOBILE_GYSJ:"mobile_gysj",NFX:"nfx",NOTIFICATIONS_JEWEL:"notifications_jewel",PAGE_UNFOLLOW:"page_unfollow",PAGE_UNFOLLOW_CHEVRON:"page_unfollow_chevron",PAGE_UNLIKE:"page_unlike",PAGE_VERIFICATION_BADGE:"page_verification_badge",PROACTIVE_WARNING_BANNER:"proactive_warning_banner",PROFILE_REPORT_BUTTON:"profile_report_button",RELATED_SEARCHES:"related_searches",REPORT_AD_BUTTON:"report_ad_button",REPORT_BUTTON:"report_button",REPORT_LONG_PRESS:"report_long_press",SCHOOL_COMMUNITY_TAGS:"school_community_tags",SEARCH_TYPEAHEAD:"search_typeahead",SNACKBAR:"snackbar",STRUCTURED_REPORT_BUTTON:"structured_report_button",TOMBSTONE:"tombstone",X_OUT:"x_out",UNKNOWN:"unknown",UNOWNED_PAGE_ACTION_MENU_REPORT_PAGE:"unowned_page_action_menu_report_page",SUPPORT_HOME_HI_PRI:"support_home_hi_pri"})}),null);
__d("NFXActionConst",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({APP_SUPPORT_REDIRECT:"APP_SUPPORT_REDIRECT",BAN_USER:"BAN_USER",BLOCK_ACTOR:"BLOCK_ACTOR",BLOCK_ACTOR_WITHOUT_DELAY:"BLOCK_ACTOR_WITHOUT_DELAY",BLOCK_APP:"BLOCK_APP",BLOCK_MESSAGES:"BLOCK_MESSAGES",BLOCK_PAGE:"BLOCK_PAGE",CLOSE_OLD_PROFILE:"CLOSE_OLD_PROFILE",CONTACT_FORM:"CONTACT_FORM",CONTACT_APP_DEVELOPER:"CONTACT_APP_DEVELOPER",COMMENT_MODERATION:"COMMENT_MODERATION",OPEN_COMPOSER:"OPEN_COMPOSER",DELETE:"DELETE",DELETE_AND_BLOCK:"DELETE_AND_BLOCK",DIDNT_RECEIVE_GAME_ITEM:"DIDNT_RECEIVE_GAME_ITEM",EDIT:"EDIT",EDIT_SENSITIVE_CONTENT:"EDIT_SENSITIVE_CONTENT",EDIT_SENSITIVE_CONTENT_WWW:"EDIT_SENSITIVE_CONTENT_WWW",EXPLORE_SEE_LESS:"EXPLORE_SEE_LESS",FOX_UNFOLLOW:"FOX_UNFOLLOW",FRX_PROFILE_REPORT_CONFIRMATION:"FRX_PROFILE_REPORT_CONFIRMATION",HIGHLIGHTS_UNFOLLOW:"HIGHLIGHTS_UNFOLLOW",CHEVRON_FEEDBACK_ENTRYPOINT:"CHEVRON_FEEDBACK_ENTRYPOINT",SAVE:"SAVE",HACKED_NOTIFY:"HACKED_NOTIFY",HELP_CENTER:"HELP_CENTER",HIDE_ADVERTISER:"HIDE_ADVERTISER",HIDE_FROM_TIMELINE:"HIDE_FROM_TIMELINE",HIDE_AGGREGATION_FROM_TIMELINE:"HIDE_AGGREGATION_FROM_TIMELINE",HIDE_PHOTO_FROM_TIMELINE:"HIDE_PHOTO_FROM_TIMELINE",HIDE_RESEARCH_POLLS:"HIDE_RESEARCH_POLLS",HIDE_FEED_TOPIC:"HIDE_FEED_TOPIC",HIDE_FEED_RECOMMENDATIONS:"HIDE_FEED_RECOMMENDATIONS",IGNORE_EVENT_INVITES:"IGNORE_EVENT_INVITES",IGNORE_MESSAGES:"IGNORE_MESSAGES",LEAVE_GROUP:"LEAVE_GROUP",LIMIT_FRIENDING_PRIVACY:"LIMIT_FRIENDING_PRIVACY",MARK_MESSAGE_THREAD_AS_SPAM:"MARK_MESSAGE_THREAD_AS_SPAM",MARK_AS_FALSE_NEWS:"MARK_AS_FALSE_NEWS",MARK_AS_SCAM:"MARK_AS_SCAM",MARK_AS_SPAM:"MARK_AS_SPAM",MARK_AS_SENSITIVE_CONTENT:"MARK_AS_SENSITIVE_CONTENT",MESSAGE:"MESSAGE",MESSENGER_REDIRECT:"MESSENGER_REDIRECT",MESSENGER_BLOCK_ACTOR:"MESSENGER_BLOCK_ACTOR",MESSENGER_GIVE_FEEDBACK_OR_REPORT:"MESSENGER_GIVE_FEEDBACK_OR_REPORT",MESSENGER_IGNORE_CONVERSATION:"MESSENGER_IGNORE_CONVERSATION",MESSENGER_LEAVE_GROUP:"MESSENGER_LEAVE_GROUP",MESSENGER_MUTE_CONVERSATION:"MESSENGER_MUTE_CONVERSATION",MESSENGER_MUTE_CONVERSATION_WITH_OPTIONS:"MESSENGER_MUTE_CONVERSATION_WITH_OPTIONS",MESSENGER_MUTE_STORY:"MESSENGER_MUTE_STORY",MESSENGER_VIEW_COMMUNITY_STANDARDS:"MESSENGER_VIEW_COMMUNITY_STANDARDS",MESSENGER_REPORT_GROUP_MEMBER:"MESSENGER_REPORT_GROUP_MEMBER",MESSENGER_REPORT_USER:"MESSENGER_REPORT_USER",MESSENGER_REPORT_MESSAGES:"MESSENGER_REPORT_MESSAGES",MESSENGER_REPORT_STORY:"MESSENGER_REPORT_STORY",NFX_AFTER_CONFIRMATION:"NFX_AFTER_CONFIRMATION",IN_APP_PAYMENTS_SUPPORT:"IN_APP_PAYMENTS_SUPPORT",PHONE_FRIEND:"PHONE_FRIEND",RECOVER_PROFILE:"RECOVER_PROFILE",REDIRECT:"REDIRECT",REDIRECT_ADS_PREFERENCES:"REDIRECT_ADS_PREFERENCES",REDIRECT_OBA_UPSELL:"REDIRECT_OBA_UPSELL",REMOVE_ADS_INTEREST:"REMOVE_ADS_INTEREST",REMOVE_EVENT:"REMOVE_EVENT",REPORT_ALREADY_REPORTED_CONTENT:"REPORT_ALREADY_REPORTED_CONTENT",REPEAT_REPORTER_REPORT_CONFIRMATION:"REPEAT_REPORTER_REPORT_CONFIRMATION",REPORT_CONTENT:"REPORT_CONTENT",REPORT_CONTENT_AFTER_CONFIRMATION:"REPORT_CONTENT_AFTER_CONFIRMATION",REPORT_CONTENT_WITH_TYPEAHEAD:"REPORT_CONTENT_WITH_TYPEAHEAD",REPORT_WORK_CONTENT:"REPORT_WORK_CONTENT",REPORT_WORK_CONTENT_WITH_REASON:"REPORT_WORK_CONTENT_WITH_REASON",REPORT_CONTENT_EDUCATION:"REPORT_CONTENT_EDUCATION",REPORT_IP_VIOLATION:"REPORT_IP_VIOLATION",REPORT_DISPUTED_ADMINS:"REPORT_DISPUTED_ADMINS",MARKETPLACE_REPORT_IP_VIOLATION:"MARKETPLACE_REPORT_IP_VIOLATION",REPORT_IMAGE_PRIVACY_VIOLATION:"REPORT_IMAGE_PRIVACY_VIOLATION",REPORT_AD_IP_VIOLATION:"REPORT_AD_IP_VIOLATION",REPORT_AD_TO_GROUP_ADMIN:"REPORT_AD_TO_GROUP_ADMIN",REPORT_PROFILE_FRAME_IP_VIOLATION:"REPORT_PROFILE_FRAME_IP_VIOLATION",REPORT_STORY_CONTENT_IP_VIOLATION:"REPORT_STORY_CONTENT_IP_VIOLATION",REPORT_TO_GROUP_ADMIN:"REPORT_TO_GROUP_ADMIN",REPORT_WITH_VIDEO_EVIDENCE:"REPORT_WITH_VIDEO_EVIDENCE",RESOLVE_PROBLEM:"RESOLVE_PROBLEM",RESOLVE_ACTOR_PROBLEM:"RESOLVE_ACTOR_PROBLEM",RESOLVE_PROBLEM_REDIRECT:"RESOLVE_PROBLEM_REDIRECT",SPAM_CLEANUP_CHECKPOINT:"SPAM_CLEANUP_CHECKPOINT",GEO_SPECIFIC_HARASSMENT_HELPLINE:"GEO_SPECIFIC_HARASSMENT_HELPLINE",TOMBSTONE_SURVEY:"TOMBSTONE_SURVEY",TOMBSTONE_IN_CONTEXT:"TOMBSTONE_IN_CONTEXT",ENABLE_TIMELINE_REVIEW:"ENABLE_TIMELINE_REVIEW",UNFOLLOW_FRIEND_LIST:"UNFOLLOW_FRIEND_LIST",UNFRIEND:"UNFRIEND",UNLIKE:"UNLIKE",UNSUBSCRIBE:"UNSUBSCRIBE",UNSUBSCRIBE_PAGE:"UNSUBSCRIBE_PAGE",UNSUBSCRIBE_DIRECTED_TARGET:"UNSUBSCRIBE_DIRECTED_TARGET",UNSUBSCRIBE_OWNER:"UNSUBSCRIBE_OWNER",UNSUBSCRIBE_RESHARER:"UNSUBSCRIBE_RESHARER",UNSUBSCRIBE_ATTACHED_STORY_ACTOR:"UNSUBSCRIBE_ATTACHED_STORY_ACTOR",UNSUBSCRIBE_ATTACHED_STORY_DIRECTED_TARGET:"UNSUBSCRIBE_ATTACHED_STORY_DIRECTED_TARGET",HIDE_APP:"HIDE_APP",SCAM_CONTACT_FORM:"SCAM_CONTACT_FORM",SHARE_PHOTO_AS_STORY:"SHARE_PHOTO_AS_STORY",SHOW_MESSAGE_PREFILLS:"SHOW_MESSAGE_PREFILLS",SNOOZE_ACTOR:"SNOOZE_ACTOR",SNOOZE_DIRECTED_TARGET:"SNOOZE_DIRECTED_TARGET",SNOOZE_OWNER:"SNOOZE_OWNER",SNOOZE_RESHARER:"SNOOZE_RESHARER",SNOOZE_ATTACHED_STORY_PRIMARY_ACTOR:"SNOOZE_ATTACHED_STORY_PRIMARY_ACTOR",SNOOZE_ATTACHED_STORY_DIRECTED_TARGET:"SNOOZE_ATTACHED_STORY_DIRECTED_TARGET",SNOOZE_DOMAIN:"SNOOZE_DOMAIN",SNOOZE_APP:"SNOOZE_APP",KEYWORD_SNOOZE_ENTRYPOINT:"KEYWORD_SNOOZE_ENTRYPOINT",REPORT_LIVING_ROOM:"REPORT_LIVING_ROOM",UNTAG:"UNTAG",UNTAG_SPONSOR_PAGE:"UNTAG_SPONSOR_PAGE",UNTAG_MEMORIALIZED_USER_FROM_THEIR_TIMELINE:"UNTAG_MEMORIALIZED_USER_FROM_THEIR_TIMELINE",HIDE:"HIDE",DONT_LIKE:"DONT_LIKE",HIDE_AD:"HIDE_AD",HIDE_AD_BREAKS:"HIDE_AD_BREAKS",HIDE_SHARED_AD_BREAK_HOST_VIDEO_STORY:"HIDE_SHARED_AD_BREAK_HOST_VIDEO_STORY",REPORT_AD:"REPORT_AD",PAGES_ACTIVE_ADS_REPORT_AD:"PAGES_ACTIVE_ADS_REPORT_AD",PAGES_ACTIVE_ADS_REPORT_ITEM:"PAGES_ACTIVE_ADS_REPORT_ITEM",POLITICAL_ARCHIVE_REPORT_AD:"POLITICAL_ARCHIVE_REPORT_AD",INTERN_SHOW_ADS_DEBUGGER_INFO:"INTERN_SHOW_ADS_DEBUGGER_INFO",TESTING:"TESTING",TESTING_LOGGING:"TESTING_LOGGING",TESTING_LOGGING_IDEMPOTENT:"TESTING_LOGGING_IDEMPOTENT",HIDE_VIDEO:"HIDE_VIDEO",HIDE_AD_WITH_AD_ALREADY_OWNED:"HIDE_AD_WITH_AD_ALREADY_OWNED",HIDE_AD_WITH_REMOVE_ITEM_FROM_AD:"HIDE_AD_WITH_REMOVE_ITEM_FROM_AD",HIDE_TOPIC_MISCLASSIFICATION:"HIDE_TOPIC_MISCLASSIFICATION",AD_ALREADY_OWNED:"AD_ALREADY_OWNED",REMOVE_ITEM_FROM_AD:"REMOVE_ITEM_FROM_AD",HEAD_PUBLISHER_APP_MENTIONS_BAN:"HEAD_PUBLISHER_APP_MENTIONS_BAN",HEAD_PUBLISHER_APP_MENTIONS_HIDE:"HEAD_PUBLISHER_APP_MENTIONS_HIDE",GOV_DIGEST_OPT_OUT:"GOV_DIGEST_OPT_OUT",VOTING_REMINDER_WRONG_LOCATION:"VOTING_REMINDER_WRONG_LOCATION",ELECTIONS_HIDE:"ELECTIONS_HIDE",LESS_FROM_ACTOR:"LESS_FROM_ACTOR",LESS_FROM_DIRECTED_TARGET:"LESS_FROM_DIRECTED_TARGET",LESS_FROM_ATTACHED_STORY_ACTOR:"LESS_FROM_ATTACHED_STORY_ACTOR",LESS_FROM_DOMAIN:"LESS_FROM_DOMAIN",LESS_FROM_APP:"LESS_FROM_APP",LESS_FROM_THROWBACK:"LESS_FROM_THROWBACK",THROWBACK_PREFERENCES:"THROWBACK_PREFERENCES",NEWSFEED_SETTINGS:"NEWSFEED_SETTINGS",BLOCK_SETTINGS:"BLOCK_SETTINGS",WRITE_IN:"WRITE_IN",DIRECT_SUPPORT:"DIRECT_SUPPORT",APP_INVITE_BLOCK_APP:"APP_INVITE_BLOCK_APP",APP_INVITE_BLOCK_USER:"APP_INVITE_BLOCK_USER",PAGES_LIKE_CHECKUP:"PAGES_LIKE_CHECKUP",COMPASSION_SUPPORT:"COMPASSION_SUPPORT",PYMA_XOUT:"PYMA_XOUT",PYMA_OPT_OUT:"PYMA_OPT_OUT",JOB_XOUT:"JOB_XOUT",JOB_UNIT_XOUT:"JOB_UNIT_XOUT",DELETE_FUNDRAISER:"DELETE_FUNDRAISER",HIDE_BREAKING_NEWS_CARD:"HIDE_BREAKING_NEWS_CARD",HIDE_SHOW_PYMF:"HIDE_SHOW_PYMF",HIDE_PYMK:"HIDE_PYMK",SELF_HARM_HELP_CENTER:"SELF_HARM_HELP_CENTER",MEMORIALIZATION_HELP_CENTER:"MEMORIALIZATION_HELP_CENTER",UNDERAGE_HELP_CENTER:"UNDERAGE_HELP_CENTER",HACKED_HELP_CENTER:"HACKED_HELP_CENTER",BULLYING_HELP_CENTER:"BULLYING_HELP_CENTER",STOLEN_GOODS_HELP_CENTER:"STOLEN_GOODS_HELP_CENTER",PRE_REPORT_CAPTCHA_SCREEN_REDIRECT:"PRE_REPORT_CAPTCHA_SCREEN_REDIRECT",PRE_REPORT_CONFIRMATION_SCREEN_REDIRECT:"PRE_REPORT_CONFIRMATION_SCREEN_REDIRECT",REPORT_ACTION_REQUIRING_EVIDENCE:"REPORT_ACTION_REQUIRING_EVIDENCE",SUPPORT_PLATFORM_REDIRECT_MESSAGE_AUTHOR:"SUPPORT_PLATFORM_REDIRECT_MESSAGE_AUTHOR",SUPPORT_PLATFORM_REDIRECT_MESSAGE_FRIEND:"SUPPORT_PLATFORM_REDIRECT_MESSAGE_FRIEND",SUPPORT_PLATFORM_REDIRECT_SEND_CARD:"SUPPORT_PLATFORM_REDIRECT_SEND_CARD",SUPPORT_PLATFORM_REDIRECT_LEARN:"SUPPORT_PLATFORM_REDIRECT_LEARN",WAIST_REDIRECT:"WAIST_REDIRECT",VIEW_ADS_REDIRECT:"VIEW_ADS_REDIRECT",AD_ARCHIVE_REDIRECT:"AD_ARCHIVE_REDIRECT",FRX_PROFILE_REPORT_CONFIRMATION_REDIRECT:"FRX_PROFILE_REPORT_CONFIRMATION_REDIRECT",FRX_REPORT_CONFIRMATION_SCREEN:"FRX_REPORT_CONFIRMATION_SCREEN",FRX_POLICY_CHECKLIST_REDIRECT:"FRX_POLICY_CHECKLIST_REDIRECT",FRX_NT_POLICY_CHECKLIST:"FRX_NT_POLICY_CHECKLIST",FRX_TEXT_HIGHLIGHTER_REDIRECT:"FRX_TEXT_HIGHLIGHTER_REDIRECT",DISABLE_IG_UNCONNECTED_STORIES:"DISABLE_IG_UNCONNECTED_STORIES",FRX_NT_REPORT_GROUP_CHAT_MEMBER_REDIRECT:"FRX_NT_REPORT_GROUP_CHAT_MEMBER_REDIRECT",FRX_NT_REPORT_GROUP_CHAT_MEMBER:"FRX_NT_REPORT_GROUP_CHAT_MEMBER",SIMPLE_ACTION_WHICH_REDIRECTS:"SIMPLE_ACTION_WHICH_REDIRECTS",MARKETPLACE_MESSENGER_REPORT_CONVERSATION:"MARKETPLACE_MESSENGER_REPORT_CONVERSATION",MARKETPLACE_SUPPORT_CALL:"MARKETPLACE_SUPPORT_CALL",MARKETPLACE_SUPPORT_CHAT:"MARKETPLACE_SUPPORT_CHAT",MARKETPLACE_SUPPORT_SMS:"MARKETPLACE_SUPPORT_SMS",CREATE_STRUCTURED_REPORT:"CREATE_STRUCTURED_REPORT",OPEN_SUPPORT_INBOX_FOR_STRUCTURED_REPORT:"OPEN_SUPPORT_INBOX_FOR_STRUCTURED_REPORT",FRX_POLICY_EDUCATION_REDIRECT:"FRX_POLICY_EDUCATION_REDIRECT",FRX_NT_POLICY_EDUCATION:"FRX_NT_POLICY_EDUCATION",FRX_PROCESS_EDUCATION_REDIRECT:"FRX_PROCESS_EDUCATION_REDIRECT",FRX_NT_PROCESS_EDUCATION:"FRX_NT_PROCESS_EDUCATION",MONETIZATION_CONTENT_GUIDELINES_HELP_CENTER_REDIRECT:"MONETIZATION_CONTENT_GUIDELINES_HELP_CENTER_REDIRECT",NCII_HELP_CENTER_REDIRECT:"NCII_HELP_CENTER_REDIRECT",PRIVACY_SHORTCUTS_REDIRECT:"PRIVACY_SHORTCUTS_REDIRECT",NEWS_FEED_PREFERENCES:"NEWS_FEED_PREFERENCES",BLACKLIST_CONTENT_REDIRECT:"BLACKLIST_CONTENT_REDIRECT",CLEAR_HISTORY_HELP_CENTER_REDIRECT:"CLEAR_HISTORY_HELP_CENTER_REDIRECT"})}),null);
__d("NFXContextType",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({ENT_MESSAGE_THREAD:1,ENT_REPORTABLE:2,ENT_SERP:3,ENT_STORY:4,PAGE_ACTIVE_ADS:5,POLITICAL_ARCHIVE_ADS:6,SUPPORT_INBOX:7,TESTING:8,REPORTABLE_AD:9,TOP_LEVEL:10})}),null);
__d("NFXStoryLocation",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({REJECT_FRIEND_REQUEST:"reject_friend_request",FEED:"feed",HOVERCARD:"hovercard",VIDEO_LIST_CHANNEL:"video_list_channel",VIDEO_PLAYLIST_CHANNEL:"video_playlist_channel",WATCHED_VIDEOS_CHANNEL:"watched_videos_channel",EXPLORE_FEED:"explore_feed",PROFILE_SELF:"profile_self",PROFILE_SOMEONE_ELSE:"profile_someone_else",FNRP_AUTOMATED_SCRIPT:"fnrp_automated_script",PAGE:"page",PAGE_INBOX:"page_inbox",PAGE_BLUE_VERIFICATION_BADGE:"page_blue_verification_badge",PAGE_GRAY_VERIFICATION_BADGE:"page_gray_verification_badge",PAGE_SHOP:"page_shop",LIKED_PAGES:"liked_pages",PERMALINK:"permalink",PHOTO_VIEWER:"photo_viewer",PHOTO_ALBUM:"photo_album",PAGE_REVIEW:"page_review",POPULAR_AT:"popular_at",CURATED_SECTION:"curated_section",GROUP:"group",SUGGESTED_GROUP:"suggested_group",EVENT:"event",SEARCH:"search",SERP:"serp",UNKNOWN:"unknown",PROFILE_REPORTING_FLOW:"profile_reporting_flow",HEAD_PUBLISHER_APP_MENTIONS_FEED:"head_publisher_app_mentions_feed",MESSENGER:"messenger",MESSENGER_MONTAGE_VIEWER:"messenger_montage_viewer",MESSENGER_THREAD:"messenger_thread",FUNDRAISER_PAGE_FEED:"fundraiser_page_feed",FUNDRAISER_PERSON_TO_CHARITY:"fundraiser_person_to_charity",FUNDRAISER_PERSON_FOR_PERSON:"fundraiser_person_for_person",CRISIS_FEED:"crisis_feed",CIVIC_PROPOSAL:"civic_proposal",SETTINGS:"settings",LIVE_MAP:"live_map",LIVING_ROOM:"living_room",JOB_APPLICATION:"job_application",JOB_BROWSER:"job_browser",JOB_DETAIL_VIEW:"job_detail_view",JOBS_NEAR_YOU:"jobs_near_you",JOB_RECOMMENDATION_UNIT:"job_recommendation_unit",CONTENT_OVERLAY:"content_overlay",CHEVRON:"chevron",CHEVRON_GLYPH:"glyph",VIDEO_INLINE_PIVOT:"video_inline_pivot",OBJECTIONABLE_CONTENT_FILTER:"objectionable_content_filter",VIEW_PAGE_ADS:"view_page_ads",POLITICAL_ARCHIVE_ADS:"political_archive_ads",AD_LIBRARY_V2_POLITICAL_ADS:"ad_library_v2_political_ads",FEEDBACK_COMMENT:"feedback_comment",FRIEND_LIST:"friend_list",NOTIFICATION:"notification",IG_FEED:"ig_feed",IG_DISCOVER:"ig_discover",IG_POST:"ig_post",IG_PROFILE:"ig_profile",IG_STORY:"ig_story",IG_COMMENTS:"ig_comments",IG_DIRECT_MESSAGES:"ig_direct_messages",IG_LIVE:"ig_live",IG_PRODUCT:"ig_product",IG_IN_APP_BROWSER:"ig_in_app_browser",MESSENGER_THREAD_ACTION_PANEL:"messenger_thread_action_panel",MESSENGER_CONTACT_DETAILS:"messenger_contact_details",MESSENGER_DIRECT_THREAD_DETAILS:"messenger_direct_thread_details",MESSENGER_GROUP_THREAD_DETAILS:"messenger_group_thread_details",MESSENGER_DIRECT_THREAD_MESSAGE_REQUEST:"messenger_direct_thread_message_request",MESSENGER_GROUP_THREAD_MESSAGE_REQUEST:"messenger_group_thread_message_request",MESSENGER_DIRECT_THREAD_FILTERED_REQUEST:"messenger_direct_thread_filtered_request",MESSENGER_GROUP_THREAD_FILTERED_REQUEST:"messenger_group_thread_filtered_request",MESSENGER_EMPTY_DIRECT_THREAD:"messenger_empty_direct_thread",MESSENGER_GROUP_THREAD_MEMBERS_LIST:"messenger_group_thread_members_list",MESSENGER_P2B_DIRECT_THREAD_DETAILS:"messenger_p2b_direct_thread_details",TICKER:"ticker",FULLSCREEN_VIDEO_PLAYER:"fullscreen_video_player",ACTIVITY_LOG_FACE_ALERTS:"face_alerts",HELP_COMMUNITY:"help_community",SUPPORT_INBOX:"support_inbox",APP_INVITES_FEED:"app_invites_feed",CHAINING_FEED:"chaining_feed",SOCIAL_REPORTING_REDIRECT:"social_reporting_redirect",WWW_CHAT_HEAD:"www_chat_head",THROWBACK:"throwback",POST_TO_PAGE:"post_to_page",ACTIVITY_LOG:"activity_log",VIDEO_CHANNEL:"video_channel",VIDEO_CHANNELS:"video_channels",VIDEO_HOME:"video_home",REVIEWS_FEED:"reviews_feed",BACKSTAGE:"backstage",MESSENGER_ENCRYPTED_THREAD:"messenger_encrypted_thread",LOCAL_NEWS:"local_news",PLANNED_VIEWING_CURATED:"planned_viewing_curated",UI_EXPLORER_EXAMPLE:"ui_explorer_example",SERP_CONSOLE:"serp_console",LOL_FEED:"lol_feed",MARKETPLACE_ADS:"marketplace_ads",MARKETPLACE_BSG_PROFILE:"marketplace_bsg_profile",MARKETPLACE_BUY_SELL_GROUP_HOME:"marketplace_buy_sell_group_home",MARKETPLACE_PDP:"marketplace_pdp",MARKETPLACE_PDP_SELLER:"marketplace_pdp_seller",MARKETPLACE_PDP_QUESTION_AND_ANSWER:"marketplace_pdp_question_and_answer",MARKETPLACE_PROFILE:"marketplace_profile",MARKETPLACE_PROFILE_BUYER:"marketplace_profile_buyer",MARKETPLACE_PROFILE_SELLER:"marketplace_profile_seller",MARKETPLACE_RATING_CONFIRMATION:"marketplace_rating_confirmation",MARKETPLACE_RATING_CONFIRMATION_BUYER:"marketplace_rating_confirmation_buyer",MARKETPLACE_RATING_CONFIRMATION_SELLER:"marketplace_rating_confirmation_seller",MARKETPLACE_RATING_FLOW:"marketplace_rating_flow",MARKETPLACE_RATING_FLOW_BUYER:"marketplace_rating_flow_buyer",MARKETPLACE_RATING_FLOW_SELLER:"marketplace_rating_flow_seller",MARKETPLACE_RATE_BUYER:"marketplace_rate_buyer",MARKETPLACE_RATE_SELLER:"marketplace_rate_seller",MARKETPLACE_SCALED_RATE_BUYER:"marketplace_scaled_rate_buyer",MARKETPLACE_SCALED_RATE_SELLER:"marketplace_scaled_rate_seller",MARKETPLACE_B2C_REVIEW:"marketplace_b2c_review",MARKETPLACE_THREAD:"marketplace_thread",MARKETPLACE_THREAD_BUYER:"marketplace_thread_buyer",MARKETPLACE_THREAD_SELLER:"marketplace_thread_seller",MARKETPLACE_MESSENGER_REPORT_BUYER:"marketplace_messenger_report_buyer",MARKETPLACE_MESSENGER_REPORT_SELLER:"marketplace_messenger_report_seller",CANONICAL_MESSENGER_REPORT_BUYER:"canonical_messenger_report_buyer",CANONICAL_MESSENGER_REPORT_SELLER:"canonical_messenger_report_seller",MARKETPLACE_SHOP_PDP:"marketplace_shop_pdp",MARKETPLACE_SHOP_PDP_SELLER:"marketplace_shop_pdp_seller",MARKETPLACE_C2C_TRANSACTION_SURVEY:"marketplace_c2c_transaction_survey",NON_INTERACTIVE_ITEM_PDP:"non_interactive_item_pdp",MENTORSHIP_APPLICATION_TAB:"mentorship_application_tab",MENTORSHIP_ADMIN_ASSISTED_GALLERY:"mentorship_admin_assisted_gallery",MENTORSHIP_PEER_TO_PEER_GALLERY:"mentorship_peer_to_peer_gallery",POLITICAL_ISSUE_MODULE:"political_issue_module",ELECTION_HUB:"election_hub",DIRECT_MESSAGING:"direct_messaging",CAMERA_MEDIA_EFFECT:"camera_media_effect",PROFILE_DEPRECATED:"profile",TIMELINE_DEPRECATED:"timeline",TIMELINE_REVIEW:"timeline_review",BREAKUP_FLOW:"breakup_flow",ASYNC_TASK_DO_NOT_USE:"async",INSTANT_ARTICLES:"instant_articles",INSTANT_ARTICLE_WEBVIEW_AD:"instant_article_webview_ad",INSTANT_ARTICLE_NATIVE_AD:"instant_article_native_ad",IN_APP_BROWSER:"in_app_browser",INSTREAM_VIDEO:"instream_video",TOPIC_PAGE:"topic_page",GAMES_FEED:"games_feed",TAG_QUARANTINE:"tag_qurantine",STONEHENGE_CONSUMPTION:"stonehenge_consumption",ARTICLE_CONTEXT:"article_context",INTEGRITY_CONTEXT:"integrity_context",PROFILE_FRAME_DISCOVERY:"profile_frame_discovery",QUICK_PROMOTION:"quick_promotion",WOODHENGE_EXCLUSIVE_FEED:"woodhenge_exclusive_feed",AUDIENCE_INSIGHTS:"audience_insights",PROJECT_NEO:"project_neo",COMPASSION_RESOURCES:"compassion_resources",FOX_FEED:"fox_feed",FOX_CHEVRON:"fox_chevron",HIGHLIGHTS_UNIT:"highlights_unit",PAGE_SURFACE_RECOMMENDATIONS:"page_surface_recommendations",SOCIAL_LEARNING_GROUP_UNITS_LIST:"social_learning_group_units_list",PREVIEW_DIALOG:"preview_dialog",STORY:"story",CREATOR_APP_INSPIRATION_FEED:"creator_app_inspiration_feed",SCHOOL_COMMUNITY:"school_community",AGORA:"agora",AGORA_EVENTS:"agora_events",PINNED_CONVERSATION:"pinned_conversation",GEMSTONE_PROFILE:"gemstone_profile",VR_PERSONA_PROFILE:"vr_persona_profile",VR_SAFE_MODE:"vr_safe_mode",KOTOTORO_FEED:"kototoro_feed",KOTOTORO_COMMENT:"kototoro_comment",BALLOT:"ballot",CANDIDATE_VIDEOS:"candidate_videos",INSTANT_GAMES:"instant_games",INSTANT_GAMES_SPOTLIGHT:"instant_games_spotlight",INSTANT_GAMES_HUB:"instant_games_hub",INSTANT_GAMES_MESSENGER:"instant_games_messenger",APP_CENTER:"app_center",APP_PERMISSIONS_DIALOG:"app_permissions_dialog",CLEAR_HISTORY:"clear_history",GAME_DETAIL:"game_detail",GAME_PAGE:"game_page",GAMES_REQUESTS:"games_requests",GROUP_INSTALLED_APPS:"group_installed_apps",IN_GAME:"in_game",MOBILE_APP_PERMISSIONS:"mobile_app_permissions",MOBILE_REMOVED_APPS:"mobile_removed_apps",PAGE_LOGS:"page_logs",PERMISSIONS_LEGALESE:"permissions_legalese",REMOVED_APP_DIALOG:"removed_app_dialog",DEVELOPER_COMMUNITY_POST:"developer_community_post",PYML:"pyml",PORTAL_VIDEO:"portal_video",SAVE_COLLECTION_VIEW:"save_collection_view",SAVE_ITEM_VIEW:"save_item_view",APP_BOOKMARKS:"app_bookmarks",BSG_FOR_SALE_LIVE_VIDEO_BROADCAST_IN_PROGRESS:"bsg_for_sale_live_video_broadcast_in_progress",BSG_FOR_SALE_LIVE_VIDEO_BROADCAST_COMPLETE:"bsg_for_sale_live_video_broadcast_complete",BSG_FOR_SALE_LIVE_VIDEO_BROADCAST_IN_PROGRESS_FROM_POST:"bsg_for_sale_live_video_broadcast_in_progress_from_post",BSG_FOR_SALE_LIVE_VIDEO_BROADCAST_COMPLETE_FROM_POST:"bsg_for_sale_live_video_broadcast_complete_from_post"})}),null);
__d("StickerInterfaces",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({MESSAGES:"messages",NEO:"neo",COMMENTS:"comments",STICKERED:"stickered",COMPOSER:"composer",POSTS:"posts",FRAMES:"frames",SMS:"sms",MONTAGE:"montage"})}),null);
__d("NFXContextFactory",["FBLogger","FRXEntryPoint","NFXActionConst","NFXContextType","uuid"],(function(a,b,c,d,e,f){"use strict";__p&&__p();function g(a){var c=function(a,b){if(b!==null)return b};return JSON.stringify({reportable_ent_token:a.reportable_ent_token,story_location:a.story_location,entry_point:a.entry_point,type:a.type,session_id:b("uuid")(),initial_action_name:a.initial_action_name,reportable_id:a.reportable_id,page_id:a.page_id,responsible_id:a.responsible_id},c)}function a(a){var c=a.reportable_ent_token,d=a.story_location,e=a.entry_point;e=e===void 0?b("FRXEntryPoint").UNKNOWN:e;a=a.responsible_id;return g({type:b("NFXContextType").ENT_MESSAGE_THREAD,story_location:d,entry_point:e,reportable_ent_token:c,responsible_id:a})}function c(a){var c=a.reportable_id,d=a.page_id;a=a.storyLocation;return g({type:b("NFXContextType").POLITICAL_ARCHIVE_ADS,story_location:a,entry_point:b("FRXEntryPoint").UNKNOWN,initial_action_name:b("NFXActionConst").POLITICAL_ARCHIVE_REPORT_AD,reportable_id:c,page_id:d})}function d(a){var c=a.reportable_ent_token,d=a.story_location,e=a.entry_point;e=e===void 0?b("FRXEntryPoint").UNKNOWN:e;a=a.initial_action_name;c===null&&b("FBLogger")("frx").warn("null or undefined reportable_ent_token in forEntReportable, location=%s entry_point=%s",d,e);return g({type:b("NFXContextType").ENT_REPORTABLE,story_location:d,entry_point:e,reportable_ent_token:c,initial_action_name:a})}e.exports={withEntReportable:d,withEntMessageThread:a,withPoliticalArchiveAds:c}}),null);
__d("FRXURI",["ActorURI","FRXEntryPoint","NFXContextFactory","XRapidReportingDialogController"],(function(a,b,c,d,e,f){"use strict";__p&&__p();function a(a){var c=a.reportable_ent_token,d=a.story_location,e=a.entry_point;e=e===void 0?b("FRXEntryPoint").UNKNOWN:e;var f=a.responsible_id;a=a.actor_id;c=b("NFXContextFactory").withEntMessageThread({reportable_ent_token:c,story_location:d,entry_point:e,responsible_id:f});d=b("XRapidReportingDialogController").getURIBuilder().setString("context",c).getURI();a!=null&&(d=b("ActorURI").create(d,a));return d}function c(a){var c=a.reportable_ent_token,d=a.story_location,e=a.entry_point;e=e===void 0?b("FRXEntryPoint").UNKNOWN:e;var f=a.initial_action_name;a=a.actor_id;c=b("NFXContextFactory").withEntReportable({reportable_ent_token:c,story_location:d,entry_point:e,initial_action_name:f});d=b("XRapidReportingDialogController").getURIBuilder().setString("context",c).getURI();a!=null&&(d=b("ActorURI").create(d,a));return d}e.exports={withEntMessageThread:a,withEntReportable:c}}),null);
__d("isEventSupported",["fbjs/lib/ExecutionEnvironment"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g;b("fbjs/lib/ExecutionEnvironment").canUseDOM&&(g=document.implementation&&document.implementation.hasFeature&&document.implementation.hasFeature("","")!==!0);function a(a,c){__p&&__p();if(!b("fbjs/lib/ExecutionEnvironment").canUseDOM||c&&!("addEventListener"in document))return!1;c="on"+a;var d=c in document;if(!d){var e=document.createElement("div");e.setAttribute(c,"return;");d=typeof e[c]==="function"}!d&&g&&a==="wheel"&&(d=document.implementation.hasFeature("Events.wheel","3.0"));return d}e.exports=a}),null);