/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * System-Config-Server
 * Copyright (C) Bradley Clemetson 2012 <brad@codeprogrammers.net>
 * 
System-Config-Server is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * System-Config-Server is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#include "NetworkService.h"

NetworkService::NetworkService()
{
	serviceName = "Network";
	gtkBuilderFilePath = "/home/brad/dev/System-Config-Server/src/Modules/network/NetworkService.glade";
	loadBuilderFile();
	LoadWidgets();
	ConnectSignalHandlers();

	testInterface = new NetworkInterfaceViewController();
	testInterface->ethernetName = new Glib::ustring("eth0");
}

void NetworkService::LoadWidgets()
{
	g_message("Loading Network Service Widgets");
	gtkBuilder->get_widget("mainView", mainView);
	gtkBuilder->get_widget("basicNetworkInterface", basicNetworkInterface);
	gtkBuilder->get_widget("interfaceSelector", interfaceSelector);

	testInterface = new NetworkInterfaceViewController;
	
	//GTK Entry

	//GTK Buttons
	gtkBuilder->get_widget("applySettings", applySettings);
	gtkBuilder->get_widget("resetSettings", resetSettings);

	basicNetworkInterface->remove();
	basicNetworkInterface->add(*testInterface->mainView);
}

void NetworkService::ConnectSignalHandlers()
{
}

void NetworkService::CheezTest()
{
	g_message("We haz success Services Connectors!");
}