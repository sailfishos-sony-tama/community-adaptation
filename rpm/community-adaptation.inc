Summary:        Community HW adaptation setup, %{flavour} flavour
License:        BSD-3-Clause
Name:           community-adaptation-%{flavour}
Version:        0.0.1
Release:        1
Provides:       community-adaptation
Group:          System
Source0:        %{name}-%{version}.tar.bz2
Requires:	ssu

%description
%{summary}.

%prep
%setup -q -n %{name}-%{version}

%install

%if "%{flavour}" == "testing"
touch $RPM_BUILD_ROOT/init_disable_telnet
%endif

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/

# drop adaptation-community-common as it is provided by Jolla directly
#cp adaptation-community-common.%{flavour}.ini $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/adaptation-community-common.ini

cp adaptation-community-system.ini $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/ssu/repos.d/

cp adaptation-community.%{flavour}.ini $RPM_BUILD_ROOT/%{_datadir}/ssu/repos.d/adaptation-community.ini

%files
%defattr(-,root,root,-)
/*

