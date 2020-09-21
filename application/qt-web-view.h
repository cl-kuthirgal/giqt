/*
 * qt-web-view.h
 * Copyright (C) 2017-2019 Michael Rosset <mike.rosset@gmail.com>
 *
 * This file is part of giqt
 *
 * giqt is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 * giqt is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __QT_WEB_VIEW_H__
#define __QT_WEB_VIEW_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define QT_TYPE_WEB_VIEW (qt_web_view_get_type ())
G_DECLARE_FINAL_TYPE (QtWebView, qt_web_view, QT, WEB_VIEW, GObject)

QtWebView *qt_web_view_new (const long socket_id);

void qt_web_view_load_uri (QtWebView *self, const char *uri);

void qt_web_view_show (QtWebView *self);

void qt_web_view_reload (QtWebView *self);

void qt_web_view_set_id (QtWebView *self, guint window_id);

guint qt_web_view_get_id (QtWebView *self);

G_END_DECLS

#endif /* __QT_WEB_VIEW_H__ */
