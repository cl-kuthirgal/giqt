;; application.scm
;; Copyright (C) 2017-2019 Michael Rosset <mike.rosset@gmail.com>

;; This file is part of giqt

;; giqt is free software: you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published by the
;; Free Software Foundation, either version 3 of the License, or
;; (at your option) any later version.

;; giqt is distributed in the hope that it will be useful, but
;; WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
;; See the GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License along
;; with this program.  If not, see <http://www.gnu.org/licenses/>.

(use-modules (oop goops)
	     (g-golf)
	     (unit-test)
	     (ice-9 threads))

(gi-import "Qt")
(gi-import-by-name "Gtk" "init")

(gtk-init 0 #f)

(define-class <test-application> (<test-case>))

(define-method (test-app (self <test-application>))
  (let ((app (make <qt-application> #:application-id "org.test.widget")))
    (assert-equal "0.0.1-alpha" (qt-application-version app))
    (assert-equal 5 (qt-major-version))
    (assert-equal "org.test.widget" (slot-ref app 'application-id))))

(define-method (test-label (self <test-application>))
  (let ((label (make <qt-label> #:label "label")))
    (assert-equal "label" (qt-label-get-text label))
    (assert-equal "label" (slot-ref label 'label))))

(exit-with-summary (run-all-defined-test-cases))
