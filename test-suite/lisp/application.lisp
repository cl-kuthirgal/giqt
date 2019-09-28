;; it's easier to use quicklisp for prototyping
(load "~/quicklisp/setup.lisp")
(ql:quickload :prove)
(ql:quickload :cl-gobject-introspection)

(in-package :cl-user)
(defpackage giqt-test
  (:use :cl
        :prove))
(in-package :giqt-test)

;; TODO: remove the need for quicklisp
;; (require 'asdf)
;; (require 'sb-posix)

;; (asdf:load-asd (concatenate 'string
;;                             (sb-posix:getcwd)
;;                             "/cl-gobject-introspection/cl-gobject-introspection.asd"))

;; cl-gobject-introspection requires these packages
;;
;; cl-alexandria
;; cl-cffi
;; cl-iterate
;; cl-trivial-garbage

;; (require :cl-gobject-introspection)

(plan 3)


(defvar gtk (gir:require-namespace "Gtk"))

;; FIXME: this should not be needed when using GApplication
(gir:invoke (gtk 'init) '())

(let* ((qt (gir:require-namespace "Qt"))
       (application (gir:invoke (qt "Application" 'new)))
       (label (gir:invoke (qt "Label" 'new) "Hello GNU, from lisp!"))
       (window (gir:invoke (qt "Widget" 'new)))
       )
  (is "0.0.1-alpha" (gir:invoke (application 'version)))
  (is 5 (gir:invoke (qt 'major_version)))
  (is "org.unknown" (gir:property application 'application-id))
  (gir:invoke (window 'add) label)
  (gir:connect application
               :activate (lambda (x)
                           (gir:invoke (window 'show-all))))
  (gir:invoke (application 'start)))

(finalize)
