<?hh // partial

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.splsubject.php )
 *
 * The SplSubject interface is used alongside SplObserver to implement the
 * Observer Design Pattern.
 *
 */
interface SplSubject {
  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splsubject.attach.php )
   *
   * Attaches an SplObserver so that it can be notified of updates. Warning:
   * This function is currently not documented; only its argument list is
   * available.
   *
   * @observer   mixed   The SplObserver to attach.
   *
   * @return     mixed   No value is returned.
   */
  public function attach(SplObserver $observer);
  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splsubject.detach.php )
   *
   * Detaches an observer from the subject to no longer notify it of
   * updates. Warning: This function is currently not documented; only its
   * argument list is available.
   *
   * @observer   mixed   The SplObserver to detach.
   *
   * @return     mixed   No value is returned.
   */
  public function detach(SplObserver $observer);
  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splsubject.notify.php )
   *
   * Notifies all attached observers. Warning: This function is currently
   * not documented; only its argument list is available.
   *
   * @return     mixed   No value is returned.
   */
  public function notify();
}