/**
 *
 * Copyright (C) 2016 Marco Scarpetta
 * 
 * This file is part of Scopa.
 * 
 * Scopa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Scopa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Scopa.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QApplication* app)
{
    this->setCentralWidget(&view);
    
    page = new WebEnginePage(&view);
    
    view.setPage(page);
    
    //page->load(QUrl::fromLocalFile(QDir::currentPath() + "/index.html"));
    QString basePath = QCoreApplication::applicationDirPath() + "/../../../../index.html";
    page->load(QUrl::fromLocalFile(basePath));
    
    QObject::connect(&view, SIGNAL(titleChanged(QString)),
                     this, SLOT(setWindowTitle(QString)));
    
    QObject::connect(&view, SIGNAL(iconChanged(QIcon)),
                     this, SLOT(updateIcon(QIcon)));
}

void MainWindow::updateIcon(QIcon icon)
{
    this->setWindowIcon(icon);
}
