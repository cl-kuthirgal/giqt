/*
 * qt-line-edit.h
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

#ifndef __QT_LINE_EDIT_H__
#define __QT_LINE_EDIT_H__

#include <qt-widget.h>

G_BEGIN_DECLS

#define QT_TYPE_LINE_EDIT             (qt_line_edit_get_type ())
G_DECLARE_FINAL_TYPE (QtLineEdit, qt_line_edit, QT, LINE_EDIT, QtWidget)

typedef struct _QtLineEdit QtLineEdit;
typedef struct _QtLineEditPrivate QtLineEditPrivate;

struct _QtLineEditClass
{
  QtWidgetClass parent_class;
};

struct _QtLineEdit
{
  GtkContainer parent_instance;

  QtLineEditPrivate *priv;
};

G_END_DECLS

#endif /* __QT_LINE_EDIT_H__ */

// Local Variables:
// do-clang-format: 0
// End:
