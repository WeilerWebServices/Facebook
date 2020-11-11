/**
* Facebook Internet Explorer Toolbar Software License 
* Copyright (c) 2009 Facebook, Inc. 
*
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (which, together with any graphical images included with such
* software, are collectively referred to below as the "Software") to (a) use,
* reproduce, display, distribute, execute, and transmit the Software, (b)
* prepare derivative works of the Software (excluding any graphical images
* included with the Software, which may not be modified or altered), and (c)
* permit third-parties to whom the Software is furnished to do so, all
* subject to the following:
*
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.  
*
* Facebook, Inc. retains ownership of the Software and all associated
* intellectual property rights.  All rights not expressly granted in this
* license are reserved by Facebook, Inc.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/ 

#ifndef URLUTILS_H
#define URLUTILS_H

#include "../util/StringUtils.h"


#include <map>
#include <vector>

/**
 *
 * Diffrent helpers for building urls for
 * actions such as: user profile, pokes, 
 * wall posts etc
 * typical url consist of 
 * http://www.facebook.com/ +  page + ?src=fftb
 * for instatnce:
 * http://www.facebook.com/editaccount.php?src=fftb
 * 
 */
namespace facebook {
   // pages names   
   const String kFacebookRoot = _T("http://www.facebook.com/");
   const String kProfilePage = _T("profile.php");
   const String kNetworksPage = _T("networks");
   const String kInboxPage = _T("inbox.php");
   const String kNotesPage = _T("notes.php");
   const String kGroupsPage = _T("groups.php");
   const String kEventsPage = _T("events.php");
   const String kFriendsPage = _T("friends/");
   const String kPostedImagesPage = _T("posted.php");
   const String kAccountPage = _T("editaccount.php");
   const String kPrivacyPage = _T("privacy/");
   const String kRequestsPage = _T("reqs.php");
   const String kComposePage = _T("compose.php");
   const String kPhotosPage = _T("photos.php");
   const String kPokesPage = _T("pokes.php");
   const String kWallPostsPage = _T("wallposts.php");
   const String kSearchPage = _T("s.php");
   const String kMessagesPage = _T("inbox/");
   const String kSharePage = _T("sharer.php");
   const String kHomePage = _T("home.php");
   const String kAutorizePage = _T("authorize.php");
   const String kLogoutPage = _T("logout.php");

   // full urls
   const String kProfileUrl = kFacebookRoot + kProfilePage;
   const String kFriendsUrl = kFacebookRoot + kFriendsPage;
   const String kNetworksUrl = kFacebookRoot + kAccountPage + _T("?networks");
   const String kInboxUrl = kFacebookRoot + kMessagesPage;
   const String kPhotosUrl = kFacebookRoot + kPhotosPage;
   const String kNotesUrl = kFacebookRoot + kNotesPage;
   const String kGroupsUrl = kFacebookRoot + kGroupsPage;
   const String kEventsUrl = kFacebookRoot + kEventsPage;
   const String kPostedItemsUrl = kFacebookRoot + kPostedImagesPage;
   const String kAccountUrl = kFacebookRoot + kAccountPage;
   const String kPrivacyUrl = kFacebookRoot + kPrivacyPage;
   const String kFriendsRequestsUrl = kFacebookRoot + kRequestsPage + _T("#friend");
   const String kMessagesUrl = kFacebookRoot + kMessagesPage;
   const String kPokesUrl = kFacebookRoot + kPokesPage;
   const String kEventsInvitationsUrl = kFacebookRoot + kRequestsPage + _T("#event");
   const String kGroupsInvitationsUrl = kFacebookRoot + kRequestsPage +_T("#group");
   const String kHomePageUrl = kFacebookRoot + kHomePage;
   const String kSharePageUrl = kFacebookRoot + kSharePage;
   const String kAutorizePageUrl = kFacebookRoot + kAutorizePage;
   const String kLogoutPageUrl = kFacebookRoot + kLogoutPage;
   const String kRestServer = _T("http://api.facebook.com/restserver.php");
   const String kApiKey = _T("9dd2c0eeff42dba6e695f7f9e10d6d83");
   const String kSecret = _T("8a54891d002d13a1fcfc430fa37f21ab");
   const String kLoginUrl = _T("http://www.facebook.com/login.php");
   const String kApiVer = _T("1.0");

   const String kAutorizeUrl = kAutorizePageUrl + _T("?api_key=") + kApiKey +
                               _T("&ver=") + kApiVer + _T("&ext_perm=status_update");

   const String kCustomActionPrefix = _T("app");
   
   /**
    * Build url for action
    * @param actionPage an string that contain action page (by const-ref)
    * @param userID an id of the user(by const-ref)
    * @param needEncode - whether need to url encode params
    * @return built string (by value)
    */
   String buildActionURL(const String& actionPage, const String& userID, 
     const bool needEncode);

   /**
    * Build url for search action
    * @param searchQuery a query to search(by const-ref)
    * @return url to string (by value)
    */
   String buildSearchURL(const String& searchQuery);

   /**
    * Build url for ShareContent
    * @param contentUrl - url to share
    * @param title - titler of the page to share
    * @return built string (by value)
    */
   String buildShareContentURL(const String& contentUrl, const String& title);

   /**
    * Build url for Profile of the user
    * @param userID an id of the user (by const-ref)
    * @return built string (by value)
    */
   String buildUserProfileUrl(const String& userID);

   /**
    * Build url to module resource in the following format:
    *  res://<path-to-module>/<resType>/<resId>
    *
    * @param moduleName a name of the module(by const-ref)
    * @param resType type of resource(by const)
    * @param resID a resource id (by const)
    *
    * @return URL to resource (by value)
    */
   String buildResourceUrl(const String& moduleName,  const UINT resType, const UINT resID);

   /**
    * Build url to module resource with RT_HTML type in the following format:
    *  res://<path-to-module>/<RT_HTML value>/<resId>
    *
    * @param moduleName a name of the module(by const-ref)
    * @param resID a resource id (by const)
    *
    * @return URL to resource (by value)
    */
   String buildHtmlResourceUrl(const String& moduleName, const UINT resID);

   /**
    * Build url for user status
    * @param userID an id of the user(by const-ref)
    * @return built string (by value)
    */
   String buildUserStatusUrl(const String& userID);

   /**
    * Build url for user inbox
    * @return built string (by value)
    */
   String buildUserInboxUrl();

   /**
    * Build url for poke friend
    * @return built string (by value)
    */
   String buildPokeFriendUrl();

   /**
    * Build url for friends request
    * @return built string (by value)
    */
   String buildFriendsRequestUrl();

   /**
    * Build url for user wall
    * @param userID an id of the user(by const-ref)
    * @return built string (by value)
    */
   String buildUserWallUrl(const String& userID);

   /**
    * Build url for user notes
    * @param userID an id of the user(by const-ref)
    * @return built string (by value)
    */
   String buildUserNotesUrl(const String& userID);

   /**
    * Build url for updated profile
    * @param userID an id of the user(by const-ref)
    * @return built string (by value)
    */
   String buildUpdateProfileUrl(const String& userID);

   /**
    *  checks whether the url is a custom action
    *  that is includes 'app prefix'
    */
   bool isCustomAction(const String& url);

   /**
    *  Encode the url into  into a MIME format called "x-www-form-urlencoded":
    *  1) The ASCII characters 'a' through 'z', 'A' through 'Z', and '0' through '9' remain the same. 
    *  2) The space character ' ' is converted into a plus sign '+'. 
    *  3) All other characters are converted into the 3-character std::string "%xy", 
    *     where xy is the two-digit hexadecimal representation of the lower 8-bits of the character. 
    *  
    */
   String encodeUrl(const String& url);

   /**
    * Checks whether the url has correct format using regexp
    * @return true if format is correct
    */
  bool isCorrectUrl(String url);
  
  
   /**
    * Split url into parts by / or \
    * @return vector of parts
    */
  std::vector<String> splitUrl(String url);


}// !namespace facebook

#endif