/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatrmi.server;

/**
 *
 * @author Nico
 */
public class ServerRunningView extends javax.swing.JFrame {

    
    private Server server;
    
    /**
     * Creates new form ClientConnectionView
     * @param s
     */
    public ServerRunningView(Server s) {
        server = s;
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        serverAdressTextField = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        serverPortTextField = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        clientNumberTextField = new javax.swing.JTextField();
        runButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMaximumSize(new java.awt.Dimension(320, 180));
        setMinimumSize(new java.awt.Dimension(320, 180));
        setPreferredSize(new java.awt.Dimension(320, 180));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });
        getContentPane().setLayout(new java.awt.FlowLayout());

        jPanel1.setMaximumSize(new java.awt.Dimension(300, 100));
        jPanel1.setMinimumSize(new java.awt.Dimension(300, 100));
        jPanel1.setPreferredSize(new java.awt.Dimension(300, 100));
        jPanel1.setLayout(new java.awt.GridLayout(3, 2));

        jLabel2.setText("Server adress : ");
        jPanel1.add(jLabel2);

        serverAdressTextField.setEditable(false);
        serverAdressTextField.setText("localhost");
        serverAdressTextField.setFocusable(false);
        serverAdressTextField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                serverAdressTextFieldActionPerformed(evt);
            }
        });
        jPanel1.add(serverAdressTextField);

        jLabel3.setText("Server port : ");
        jPanel1.add(jLabel3);

        serverPortTextField.setText("1099");
        serverPortTextField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                serverPortTextFieldActionPerformed(evt);
            }
        });
        jPanel1.add(serverPortTextField);

        jLabel1.setText("Connected :");
        jPanel1.add(jLabel1);

        clientNumberTextField.setEditable(false);
        clientNumberTextField.setText("0");
        clientNumberTextField.setFocusable(false);
        clientNumberTextField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                clientNumberTextFieldActionPerformed(evt);
            }
        });
        jPanel1.add(clientNumberTextField);

        getContentPane().add(jPanel1);

        runButton.setText("Start");
        runButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        runButton.setMaximumSize(new java.awt.Dimension(20, 100));
        runButton.setMinimumSize(new java.awt.Dimension(20, 100));
        runButton.setPreferredSize(new java.awt.Dimension(150, 30));
        runButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                runButtonActionPerformed(evt);
            }
        });
        getContentPane().add(runButton);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void serverPortTextFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_serverPortTextFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_serverPortTextFieldActionPerformed

    private void serverAdressTextFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_serverAdressTextFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_serverAdressTextFieldActionPerformed

    private void runButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_runButtonActionPerformed
        // TODO add your handling code here:
        if(server.isRunning())
        {
            if (server.stop()) {
               runButton.setText("Start");
               serverPortTextField.setEditable(true);
               serverPortTextField.setFocusable(true);
            }
        }
        else
        {
            if (server.start(serverPortTextField.getText())) {
                runButton.setText("Stop");
                serverPortTextField.setEditable(false);
                serverPortTextField.setFocusable(false);
            }
        }
    }//GEN-LAST:event_runButtonActionPerformed

    /**
     *
     * @param adress
     */
    public void diplayServerLocalAdress(String adress) {
        serverAdressTextField.setText(adress);
    }
    
    private void clientNumberTextFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_clientNumberTextFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_clientNumberTextFieldActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        // TODO add your handling code here:
        server.saveHistorics();
    }//GEN-LAST:event_formWindowClosing

    /**
     *
     * @param nb
     */
    public void setClientNumber (int nb) {
        clientNumberTextField.setText(Integer.toString(nb));
    }
    
//    /**
//     * @param args the command line arguments
//     */
//    public static void main(String args[]) {
//        /* Set the Nimbus look and feel */
//        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
//        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
//         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
//         */
//        try {
//            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
//                if ("Nimbus".equals(info.getName())) {
//                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
//                    break;
//                }
//            }
//        } catch (ClassNotFoundException ex) {
//            java.util.logging.Logger.getLogger(ServerRunningView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
//        } catch (InstantiationException ex) {
//            java.util.logging.Logger.getLogger(ServerRunningView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
//        } catch (IllegalAccessException ex) {
//            java.util.logging.Logger.getLogger(ServerRunningView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
//        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
//            java.util.logging.Logger.getLogger(ServerRunningView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
//        }
//        //</editor-fold>
//        //</editor-fold>
//
//        /* Create and display the form */
//        java.awt.EventQueue.invokeLater(new Runnable() {
//            public void run() {
//                new ServerRunningView().setVisible(true);
//            }
//        });
//    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField clientNumberTextField;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JButton runButton;
    private javax.swing.JTextField serverAdressTextField;
    private javax.swing.JTextField serverPortTextField;
    // End of variables declaration//GEN-END:variables
}
