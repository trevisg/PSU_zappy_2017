Name:           zappy-server
Version:        0.0.410
Release:        0
Patch:		384
Summary:        Dummy network game based on Asimov books universe
Group:          Applications/Game
License:        MIT
URL:            https://trevisg.github.io/PSU_zappy_2017
Vendor:         Epitech OpenSource Foundation noexist@noexist.org
Source:         https://github.com/trevisg/PSU_zappy_2017/archive/0.0.%{patch}.zip
Prefix:         %{_prefix}
Packager: 	Trevis
BuildRoot:      %{_tmppath}/%{name}-root

%description
This game is network game between trantorian teams on a
trantor style map. This a the server part
This package contains the zappy_server binary and manual page.

(if someone generate them with doxygen and cp them at some /usr/local/man)

The nature of this software means that any bugs could cause
massive data loss. While there are no known bugs at the moment,
they could exist, so please back up all important files before
running it, and do so at your own risk.


%prep
%setup -q -n %{name}-%{version}

%build
CFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=%{_prefix} --mandir=%{_mandir} --sysconfdir=/etc

make

%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

make DESTDIR=$RPM_BUILD_ROOT install
rm -rf $RPM_BUILD_ROOT%{_datadir}/doc/%{name}

%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc README AUTHORS COPYING NEWS TODO ChangeLog
%doc doc/*.html
%doc doc/*.jpg
%doc doc/*.css
%config(noreplace) /etc/%{name}.xml
%{_bindir}/icecast
%{_prefix}/share/icecast/*

%changelog

In this file, under % prep section you may noticed the macro “%setup -q -n %{name}-%{version}”. This macro executes the following command in the background.

cd /usr/src/redhat/BUILD
rm -rf icecast
gzip -dc /usr/src/redhat/SOURCES/icecast-2.3.3.tar.gz | tar -xvvf -
if [ $? -ne 0 ]; then
  exit $?
fi
cd icecast
cd /usr/src/redhat/BUILD/icecast
chown -R root.root .
chmod -R a+rX,g-w,o-w .
