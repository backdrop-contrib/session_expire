Session expire
==============

Deletes user sessions which have been idle longer than a configured time.

On busy sites, the sessions table can grow to be very large, and that can cause slow accesses to it, as well as slow writes due to locking, leading to performance bottlenecks.

By trimming the table regularly, the above bottlenecks are avoided.

Backdrop uses the PHP garbage collection mechanism to cleanup the sessions table, but this mechanism depends on PHP's configuration, and can fire for any session.

This module improves this functionality in cron. The background cron process will add consistency and predictability regardless of PHP's garbage collection configuration.

Configuration
-------------

To configure it, go to Administer -> Configuration -> User accounts -> Session expire.

The default settings delete sessions which have been idle longer than 1 week.

Current Maintainer
------------------

- David Norman (https://github.com/deekayen)

Credits
-------

- Originally written for Drupal by Khalid Baheyeldin (http://baheyeldin.com/khalid and http://2bits.com)
- Ported to Backdrop by David Norman (https://github.com/deekayen)

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
