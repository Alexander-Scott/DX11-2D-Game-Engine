﻿namespace SimpleSampleEditor
{
    partial class Editor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.panel1 = new System.Windows.Forms.Panel();
            this.lblHierachy = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.lblPrefabs = new System.Windows.Forms.Label();
            this.btnPlay = new System.Windows.Forms.Button();
            this.hierarchyListBox = new System.Windows.Forms.ListView();
            this.mainMenu1 = new System.Windows.Forms.MainMenu(this.components);
            this.menuItem1 = new System.Windows.Forms.MenuItem();
            this.menuNewScene = new System.Windows.Forms.MenuItem();
            this.menuLoadScene = new System.Windows.Forms.MenuItem();
            this.menuSaveScene = new System.Windows.Forms.MenuItem();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(257, 35);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(869, 629);
            this.panel1.TabIndex = 1;
            // 
            // lblHierachy
            // 
            this.lblHierachy.AutoSize = true;
            this.lblHierachy.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHierachy.Location = new System.Drawing.Point(72, 18);
            this.lblHierachy.Name = "lblHierachy";
            this.lblHierachy.Size = new System.Drawing.Size(97, 25);
            this.lblHierachy.TabIndex = 2;
            this.lblHierachy.Text = "Hierachy";
            // 
            // panel3
            // 
            this.panel3.Location = new System.Drawing.Point(24, 392);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(206, 270);
            this.panel3.TabIndex = 5;
            // 
            // lblPrefabs
            // 
            this.lblPrefabs.AutoSize = true;
            this.lblPrefabs.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPrefabs.Location = new System.Drawing.Point(72, 364);
            this.lblPrefabs.Name = "lblPrefabs";
            this.lblPrefabs.Size = new System.Drawing.Size(86, 25);
            this.lblPrefabs.TabIndex = 4;
            this.lblPrefabs.Text = "Prefabs";
            // 
            // btnPlay
            // 
            this.btnPlay.Location = new System.Drawing.Point(549, 6);
            this.btnPlay.Name = "btnPlay";
            this.btnPlay.Size = new System.Drawing.Size(75, 23);
            this.btnPlay.TabIndex = 8;
            this.btnPlay.Text = "PLAY";
            this.btnPlay.UseVisualStyleBackColor = true;
            // 
            // hierarchyListBox
            // 
            this.hierarchyListBox.Location = new System.Drawing.Point(12, 46);
            this.hierarchyListBox.Name = "hierarchyListBox";
            this.hierarchyListBox.Size = new System.Drawing.Size(218, 295);
            this.hierarchyListBox.TabIndex = 9;
            this.hierarchyListBox.UseCompatibleStateImageBehavior = false;
            // 
            // mainMenu1
            // 
            this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.menuItem1});
            // 
            // menuItem1
            // 
            this.menuItem1.Index = 0;
            this.menuItem1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.menuNewScene,
            this.menuLoadScene,
            this.menuSaveScene});
            this.menuItem1.Text = "Scene";
            // 
            // menuNewScene
            // 
            this.menuNewScene.Index = 0;
            this.menuNewScene.Text = "New Scene";
            this.menuNewScene.Click += new System.EventHandler(this.NewSceneClicked);
            // 
            // menuLoadScene
            // 
            this.menuLoadScene.Index = 1;
            this.menuLoadScene.Text = "Load Scene";
            this.menuLoadScene.Click += new System.EventHandler(this.LoadSceneClicked);
            // 
            // menuSaveScene
            // 
            this.menuSaveScene.Index = 2;
            this.menuSaveScene.Text = "Save Scene";
            this.menuSaveScene.Click += new System.EventHandler(this.SaveSceneClicked);
            // 
            // Editor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1184, 704);
            this.Controls.Add(this.hierarchyListBox);
            this.Controls.Add(this.btnPlay);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.lblPrefabs);
            this.Controls.Add(this.lblHierachy);
            this.Controls.Add(this.panel1);
            this.Menu = this.mainMenu1;
            this.Name = "Editor";
            this.Text = "Editor";
            this.Load += new System.EventHandler(this.EditorLoading);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label lblHierachy;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label lblPrefabs;
        private System.Windows.Forms.Button btnPlay;
        private System.Windows.Forms.ListView hierarchyListBox;
        private System.Windows.Forms.MainMenu mainMenu1;
        private System.Windows.Forms.MenuItem menuItem1;
        private System.Windows.Forms.MenuItem menuNewScene;
        private System.Windows.Forms.MenuItem menuLoadScene;
        private System.Windows.Forms.MenuItem menuSaveScene;
    }
}

